/*
 * AUTHOR: Ryan Luna
 *
 *   NEEDS DESCRIPTION
 *
 * An example diffusion controller for the foot-bot.
 *
 * This controller makes the robots behave as gas particles. The robots
 * go straight until they get close enough to another robot, in which
 * case they turn, loosely simulating an elastic collision. The net effect
 * is that over time the robots diffuse in the environment.
 *
 * The controller uses the proximity sensor to detect obstacles and the
 * wheels to move the robot around.
 *
 * This controller is meant to be used with the XML files:
 *    experimets/SIR_diffusion.argos
 */

#ifndef SIR_DIFFUSION_H
#define SIR_DIFFUSION_H

/*
 * Include some necessary headers.
 */
/* Definition of the CCI_Controller class. */
#include <argos3/core/control_interface/ci_controller.h>
/* Definition of the differential steering actuator */
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
/* Definition of the foot-bot proximity sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>

/* NEW */

/* Definition of the LEDs actuator */
#include <argos3/plugins/robots/generic/control_interface/ci_leds_actuator.h>
/* Definition of the colored blob omnidirectional camera */
   /* NOTE:
      For small swarms, enabling the sensor (and therefore causing ARGoS to
      update its readings each timestep) unconditionally does not impact performance too
      much. For large swarms, it can impact performance, and selectively
      enabling/disabling the sensor according to when each individual robot needs it
      (e.g., only when it is looking for an LED equipped entity) can increase performance
      by only requiring ARGoS to update the readings on timesteps they will be used.
   */
#include <argos3/plugins/robots/generic/control_interface/ci_colored_blob_omnidirectional_camera_sensor.h>

/* For data collection */
#include <fstream>

/* END NEW */

/*
 * All the ARGoS stuff in the 'argos' namespace.
 * With this statement, you save typing argos:: every time.
 */
using namespace argos;


/*************************************************************************************************************************************/

            /* FOR INITIALLY SUSCEPTIBLE BOT */

/*************************************************************************************************************************************/

/*
 * A controller is simply an implementation of the CCI_Controller class.
 */
class Cfb_SIR_diffusion_susceptible : public CCI_Controller {

public:

   /* Class constructor. */
   Cfb_SIR_diffusion_susceptible();

   /* Class destructor. */
   virtual ~Cfb_SIR_diffusion_susceptible() {}

   /*
    * This function initializes the controller.
    * The 't_node' variable points to the <parameters> section in the XML
    * file in the <controllers><footbot_diffusion_controller> section.
    */
   virtual void Init(TConfigurationNode& t_node);

   /*
    * This function is called once every time step.
    * The length of the time step is set in the XML file.
    */
   virtual void ControlStep();

   /*
    * This function resets the controller to its state right after the
    * Init().
    * It is called when you press the reset button in the GUI.
    * In this example controller there is no need for resetting anything,
    * so the function could have been omitted. It's here just for
    * completeness.
    */
   virtual void Reset() {}

   /*
    * Called to cleanup what done by Init() when the experiment finishes.
    * In this example controller there is no need for clean anything up,
    * so the function could have been omitted. It's here just for
    * completeness.
    */
   virtual void Destroy();

   void setState(int);

protected:

   /* state of the bot (initially susceptible = 0) */
   int state = 0;

private:

   /* Pointer to the differential steering actuator */
   CCI_DifferentialSteeringActuator* m_pcWheels;
   /* Pointer to the foot-bot proximity sensor */
   CCI_FootBotProximitySensor* m_pcProximity;

   /* NEW */

   /* Pointer to the LED actuator */
   CCI_LEDsActuator* m_pcLEDs;
   /* Pointer to the colored blob camera */
   CCI_ColoredBlobOmnidirectionalCameraSensor* m_pcBlob;

   /* helper function to handle SIR states */
   void SIR();

   /* counter for infection length */
   unsigned int count = 0;

   /* counter for steps */
   unsigned int step_count = 0;

   /* constant for infection duration */
   const unsigned int INFECTION_DURATION = 2400; // ticks

   /* END NEW */

   /*
    * The following variables are used as parameters for the
    * algorithm. You can set their value in the <parameters> section
    * of the XML configuration file, under the
    * <controllers><footbot_diffusion_controller> section.
    */

   /* Maximum tolerance for the angle between
    * the robot heading direction and
    * the closest obstacle detected. */
   CDegrees m_cAlpha;
   /* Maximum tolerance for the proximity reading between
    * the robot and the closest obstacle.
    * The proximity reading is 0 when nothing is detected
    * and grows exponentially to 1 when the obstacle is
    * touching the robot.
    */
   Real m_fDelta;
   /* Wheel speed. */
   Real m_fWheelVelocity;
   /* Angle tolerance range to go straight.
    * It is set to [-alpha,alpha]. */
   CRange<CRadians> m_cGoStraightAngleRange;

};


/*************************************************************************************************************************************/

            /* FOR INITIALLY INFECTED BOT */

/*************************************************************************************************************************************/


/*
 * A controller is simply an implementation of the CCI_Controller class.
 */
class Cfb_SIR_diffusion_infected : public CCI_Controller {

public:

   /* Class constructor. */
   Cfb_SIR_diffusion_infected();

   /* Class destructor. */
   virtual ~Cfb_SIR_diffusion_infected() {}

   /*
    * This function initializes the controller.
    * The 't_node' variable points to the <parameters> section in the XML
    * file in the <controllers><footbot_diffusion_controller> section.
    */
   virtual void Init(TConfigurationNode& t_node);

   /*
    * This function is called once every time step.
    * The length of the time step is set in the XML file.
    */
   virtual void ControlStep();

   /*
    * This function resets the controller to its state right after the
    * Init().
    * It is called when you press the reset button in the GUI.
    * In this example controller there is no need for resetting anything,
    * so the function could have been omitted. It's here just for
    * completeness.
    */
   virtual void Reset() {}

   /*
    * Called to cleanup what done by Init() when the experiment finishes.
    * In this example controller there is no need for clean anything up,
    * so the function could have been omitted. It's here just for
    * completeness.
    */
   virtual void Destroy();

private:

   /* Pointer to the differential steering actuator */
   CCI_DifferentialSteeringActuator* m_pcWheels;
   /* Pointer to the foot-bot proximity sensor */
   CCI_FootBotProximitySensor* m_pcProximity;

   /* NEW */

   /* Pointer to the LED actuator */
   CCI_LEDsActuator* m_pcLEDs;
   /* Pointer to the colored blob camera */
   CCI_ColoredBlobOmnidirectionalCameraSensor* m_pcBlob;

   /* private function to handle SIR states */
   virtual void SIR();

   /* counter for infection length */
   unsigned int count;

   /* counter for steps */
   unsigned int step_count;

   /* constant for infection duration */
   const unsigned int INFECTION_DURATION = 2400; // ticks

   /* state of the bot (initially infected = 1) */
   int state = 1;


   /* END NEW */

   /*
    * The following variables are used as parameters for the
    * algorithm. You can set their value in the <parameters> section
    * of the XML configuration file, under the
    * <controllers><footbot_diffusion_controller> section.
    */

   /* Maximum tolerance for the angle between
    * the robot heading direction and
    * the closest obstacle detected. */
   CDegrees m_cAlpha;
   /* Maximum tolerance for the proximity reading between
    * the robot and the closest obstacle.
    * The proximity reading is 0 when nothing is detected
    * and grows exponentially to 1 when the obstacle is
    * touching the robot.
    */
   Real m_fDelta;
   /* Wheel speed. */
   Real m_fWheelVelocity;
   /* Angle tolerance range to go straight.
    * It is set to [-alpha,alpha]. */
   CRange<CRadians> m_cGoStraightAngleRange;

};

#endif
