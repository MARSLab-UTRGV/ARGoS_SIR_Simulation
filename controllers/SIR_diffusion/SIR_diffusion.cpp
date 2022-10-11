/* Include the controller definition */
#include "SIR_diffusion.h"
/* Function definitions for XML parsing */
#include <argos3/core/utility/configuration/argos_configuration.h>
/* 2D vector definition */
#include <argos3/core/utility/math/vector2.h>

/****************************************/

using namespace std;

/* for data collection */
ofstream SIR_data;

/****************************************/


void Cfb_SIR_diffusion_susceptible::SIR(){

   /* update step counter */
   step_count++;

   /* Get the camera readings */
   const CCI_ColoredBlobOmnidirectionalCameraSensor::SReadings& sReadings = m_pcBlob->GetReadings();

   switch(state){

      case 0:

         /* Go through the camera readings ONLY if susceptible */
         if (! sReadings.BlobList.empty()){
            for(size_t i = 0; i < sReadings.BlobList.size(); ++i){
               
               // if the bot makes contact with and infected bot (RED bot), change to infected
               if (sReadings.BlobList[i]->Color == CColor::RED){
                  m_pcLEDs->SetAllColors(CColor::RED);
                  state = 1;
               }

            }
         }
         break;
      
      case 1:

         // increment counter for infected duration
         count++;

         // if the bot has been infected for the amount of time specified, change to recovered
         if (count >= INFECTION_DURATION){
            m_pcLEDs->SetAllColors(CColor::YELLOW);
            state = 2;
         }

         break;
      
      case 2:
         // recovered bots are immune to re-infection, do nothing
         break;

      default:
         cout << "INVALID STATE/INPUT" << endl;
         break;
   }

   /* write data to file */
   if(SIR_data.is_open()){
      SIR_data << step_count << ", " << state << endl;
   } else {
      throw 1;
      cout << "ERR: 'SIR_data.txt' could not be opened for writing..." << endl;
   }

}

/****************************************/
/****************************************/

Cfb_SIR_diffusion_susceptible::Cfb_SIR_diffusion_susceptible() :
   m_pcWheels(NULL),
   m_pcProximity(NULL),
   m_pcLEDs(NULL),
   m_pcBlob(NULL),
   m_cAlpha(10.0f),
   m_fDelta(0.5f),
   m_fWheelVelocity(2.5f),
   m_cGoStraightAngleRange(-ToRadians(m_cAlpha),
                           ToRadians(m_cAlpha)) {}

/****************************************/
/****************************************/

void Cfb_SIR_diffusion_susceptible::Init(TConfigurationNode& t_node) {
   /*
    * Get sensor/actuator handles
    *
    * The passed string (ex. "differential_steering") corresponds to the
    * XML tag of the device whose handle we want to have. For a list of
    * allowed values, type at the command prompt:
    *
    * $ argos3 -q actuators
    *
    * to have a list of all the possible actuators, or
    *
    * $ argos3 -q sensors
    *
    * to have a list of all the possible sensors.
    *
    * NOTE: ARGoS creates and initializes actuators and sensors
    * internally, on the basis of the lists provided the configuration
    * file at the <controllers><footbot_diffusion><actuators> and
    * <controllers><footbot_diffusion><sensors> sections. If you forgot to
    * list a device in the XML and then you request it here, an error
    * occurs.
    */
   m_pcWheels    = GetActuator<CCI_DifferentialSteeringActuator>("differential_steering");
   m_pcProximity = GetSensor  <CCI_FootBotProximitySensor      >("footbot_proximity"    );

   /* NEW */

   m_pcLEDs      = GetActuator<CCI_LEDsActuator                >("leds");
   m_pcBlob      = GetSensor  <CCI_ColoredBlobOmnidirectionalCameraSensor >("colored_blob_omnidirectional_camera");

   m_pcBlob->Enable();
   /* Set color GREEN */
   m_pcLEDs->SetAllColors(CColor::GREEN);

   // for data collection
   SIR_data.open ("SIR_data.txt", ios::out | ios::app);

   /* END NEW */
   /*
    * Parse the configuration file
    *
    * The user defines this part. Here, the algorithm accepts three
    * parameters and it's nice to put them in the config file so we don't
    * have to recompile if we want to try other settings.
    */
   GetNodeAttributeOrDefault(t_node, "alpha", m_cAlpha, m_cAlpha);
   m_cGoStraightAngleRange.Set(-ToRadians(m_cAlpha), ToRadians(m_cAlpha));
   GetNodeAttributeOrDefault(t_node, "delta", m_fDelta, m_fDelta);
   GetNodeAttributeOrDefault(t_node, "velocity", m_fWheelVelocity, m_fWheelVelocity);
}

/****************************************/
/****************************************/

void Cfb_SIR_diffusion_susceptible::ControlStep() {


   /* NEW */
   
   // run SIR model
   SIR();

   /* END NEW */

   /* Get readings from proximity sensor */
   const CCI_FootBotProximitySensor::TReadings& tProxReads = m_pcProximity->GetReadings();
   /* Sum them together */
   CVector2 cAccumulator;
   for(size_t i = 0; i < tProxReads.size(); ++i) {
      cAccumulator += CVector2(tProxReads[i].Value, tProxReads[i].Angle);
   }
   cAccumulator /= tProxReads.size();
   /* If the angle of the vector is small enough and the closest obstacle
    * is far enough, continue going straight, otherwise curve a little
    */
   CRadians cAngle = cAccumulator.Angle();
   if(m_cGoStraightAngleRange.WithinMinBoundIncludedMaxBoundIncluded(cAngle) &&
      cAccumulator.Length() < m_fDelta ) {
      /* Go straight */
      m_pcWheels->SetLinearVelocity(m_fWheelVelocity, m_fWheelVelocity);
   }
   else {
      /* Turn, depending on the sign of the angle */
      if(cAngle.GetValue() > 0.0f) {
         m_pcWheels->SetLinearVelocity(m_fWheelVelocity, 0.0f);
      }
      else {
         m_pcWheels->SetLinearVelocity(0.0f, m_fWheelVelocity);
      }
   }
}

/****************************************/
/****************************************/

void Cfb_SIR_diffusion_susceptible::Destroy(){
   /* close file if open */
   if (SIR_data.is_open()){
      SIR_data.close();
   }
}

/****************************************/
/****************************************/

/*
 * This statement notifies ARGoS of the existence of the controller.
 * It binds the class passed as first argument to the string passed as
 * second argument.
 * The string is then usable in the configuration file to refer to this
 * controller.
 * When ARGoS reads that string in the configuration file, it knows which
 * controller class to instantiate.
 * See also the configuration files for an example of how this is used.
 */
REGISTER_CONTROLLER(Cfb_SIR_diffusion_susceptible, "fb_sir_diffusion_susceptible_controller")


/**********************************************************************************************************************************/
                     /* FOR INITIALLY INFECTED BOT */
/**********************************************************************************************************************************/                     


Cfb_SIR_diffusion_infected::Cfb_SIR_diffusion_infected() :
   m_pcWheels(NULL),
   m_pcProximity(NULL),
   m_pcLEDs(NULL),
   m_pcBlob(NULL),
   m_cAlpha(10.0f),
   m_fDelta(0.5f),
   m_fWheelVelocity(2.5f),
   m_cGoStraightAngleRange(-ToRadians(m_cAlpha),
                           ToRadians(m_cAlpha)) {}

/****************************************/
/****************************************/

void Cfb_SIR_diffusion_infected::SIR(){

   /* update step counter */
   step_count++;

   /* An initially infected bot does not need to worry about other bots (blob camera not needed) */

   // once the infection duration time is met, change to recovered
   if (count >= INFECTION_DURATION){
      m_pcLEDs->SetAllColors(CColor::YELLOW);
      state = 2; 
   } else {count++;} // else increment duration counter

   // recovered bots don't need to worry about anything as they are immune
   if (state == 2) {}// do nothing

   /* write data to file */
   if(SIR_data.is_open()){
      SIR_data << step_count << ", " << state << endl;
   } else {
      throw 1;
      cout << "ERR: 'SIR_data.txt' could not be opened for writing..." << endl;
   }

}

/****************************************/
/****************************************/

void Cfb_SIR_diffusion_infected::Init(TConfigurationNode& t_node) {
   /*
    * Get sensor/actuator handles
    *
    * The passed string (ex. "differential_steering") corresponds to the
    * XML tag of the device whose handle we want to have. For a list of
    * allowed values, type at the command prompt:
    *
    * $ argos3 -q actuators
    *
    * to have a list of all the possible actuators, or
    *
    * $ argos3 -q sensors
    *
    * to have a list of all the possible sensors.
    *
    * NOTE: ARGoS creates and initializes actuators and sensors
    * internally, on the basis of the lists provided the configuration
    * file at the <controllers><footbot_diffusion><actuators> and
    * <controllers><footbot_diffusion><sensors> sections. If you forgot to
    * list a device in the XML and then you request it here, an error
    * occurs.
    */
   m_pcWheels    = GetActuator<CCI_DifferentialSteeringActuator>("differential_steering");
   m_pcProximity = GetSensor  <CCI_FootBotProximitySensor      >("footbot_proximity"    );

   /* NEW */

   m_pcLEDs      = GetActuator<CCI_LEDsActuator                >("leds");
   m_pcBlob      = GetSensor  <CCI_ColoredBlobOmnidirectionalCameraSensor >("colored_blob_omnidirectional_camera");

   m_pcBlob->Enable();
   /* Set color GREEN */
   m_pcLEDs->SetAllColors(CColor::RED);

   // for data collection
   SIR_data.open ("SIR_data.txt", ios::out | ios::app);

   /* END NEW */
   /*
    * Parse the configuration file
    *
    * The user defines this part. Here, the algorithm accepts three
    * parameters and it's nice to put them in the config file so we don't
    * have to recompile if we want to try other settings.
    */
   GetNodeAttributeOrDefault(t_node, "alpha", m_cAlpha, m_cAlpha);
   m_cGoStraightAngleRange.Set(-ToRadians(m_cAlpha), ToRadians(m_cAlpha));
   GetNodeAttributeOrDefault(t_node, "delta", m_fDelta, m_fDelta);
   GetNodeAttributeOrDefault(t_node, "velocity", m_fWheelVelocity, m_fWheelVelocity);
}

/****************************************/
/****************************************/

void Cfb_SIR_diffusion_infected::ControlStep() {


   /* NEW */
   
   // run SIR model
   SIR();
   
   
   /* END NEW */

   /* Get readings from proximity sensor */
   const CCI_FootBotProximitySensor::TReadings& tProxReads = m_pcProximity->GetReadings();
   /* Sum them together */
   CVector2 cAccumulator;
   for(size_t i = 0; i < tProxReads.size(); ++i) {
      cAccumulator += CVector2(tProxReads[i].Value, tProxReads[i].Angle);
   }
   cAccumulator /= tProxReads.size();
   /* If the angle of the vector is small enough and the closest obstacle
    * is far enough, continue going straight, otherwise curve a little
    */
   CRadians cAngle = cAccumulator.Angle();
   if(m_cGoStraightAngleRange.WithinMinBoundIncludedMaxBoundIncluded(cAngle) &&
      cAccumulator.Length() < m_fDelta ) {
      /* Go straight */
      m_pcWheels->SetLinearVelocity(m_fWheelVelocity, m_fWheelVelocity);
   }
   else {
      /* Turn, depending on the sign of the angle */
      if(cAngle.GetValue() > 0.0f) {
         m_pcWheels->SetLinearVelocity(m_fWheelVelocity, 0.0f);
      }
      else {
         m_pcWheels->SetLinearVelocity(0.0f, m_fWheelVelocity);
      }
   }
}

/****************************************/
/****************************************/

void Cfb_SIR_diffusion_infected::Destroy(){
   /* close file if open */
   if (SIR_data.is_open()){
      SIR_data.close();
   }
}

/****************************************/
/****************************************/

/*
 * This statement notifies ARGoS of the existence of the controller.
 * It binds the class passed as first argument to the string passed as
 * second argument.
 * The string is then usable in the configuration file to refer to this
 * controller.
 * When ARGoS reads that string in the configuration file, it knows which
 * controller class to instantiate.
 * See also the configuration files for an example of how this is used.
 */
REGISTER_CONTROLLER(Cfb_SIR_diffusion_infected, "fb_sir_diffusion_infected_controller")