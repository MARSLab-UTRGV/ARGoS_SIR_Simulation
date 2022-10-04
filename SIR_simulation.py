from xml.dom import minidom
import os

def createXML():

    xml = minidom.Document()

    # <argos-configuration>
    argos_config = xml.createElement('argos-configuration')
    xml.appendChild(argos_config)

    #   <framework>
    framework = xml.createElement('framework')
    argos_config.appendChild(framework)

    #       <system>
    system = xml.createElement('system')
    system.setAttribute('threads','0')
    framework.appendChild(system)
    #       <experiment>
    experiment = xml.createElement('experiment')
    experiment.setAttribute('length','0') # length of experiment in seconds
    experiment.setAttribute('ticks_per_second','10')
    experiment.setAttribute('random_seed','124')
    framework.appendChild(experiment)
    #   </framework>

    #   <controllers>
    controllers = xml.createElement('controllers')
    argos_config.appendChild(controllers)

    #       <fb_sir_diffusion_susceptible_controller>
    fb_susceptible = xml.createElement('fb_sir_diffusion_susceptible_controller')
    fb_susceptible.setAttribute('id','fdc_s')
    fb_susceptible.setAttribute('library','build/controllers/SIR_diffusion/libSIR_diffusion.so')
    controllers.appendChild(fb_susceptible)

    #           <actuators>
    actuators = xml.createElement('actuators')
    fb_susceptible.appendChild(actuators)

    #               <differential_steering>
    dif_steering = xml.createElement('differential_steering')
    dif_steering.setAttribute('implementation','default')
    actuators.appendChild(dif_steering)

    #               <leds>
    leds = xml.createElement('leds')
    leds.setAttribute('implementation','default')
    leds.setAttribute('medium','leds')
    actuators.appendChild(leds)
    #           </actuators

    #           <sensors>
    sensors = xml.createElement('sensors')
    fb_susceptible.appendChild(sensors)

    #               <footbot_proximity>
    fb_prox = xml.createElement('footbot_proximity')
    fb_prox.setAttribute('implementation','default')
    sensors.appendChild(fb_prox)

    #               <colored_blob_omnidirectional_camera>
    blobcam = xml.createElement('colored_blob_omnidirectional_camera')
    blobcam.setAttribute('implementation','rot_z_only')
    blobcam.setAttribute('medium','leds')
    blobcam.setAttribute('show_rays','true')
    sensors.appendChild(blobcam)
    #           </sensors>

    #           <params>
    params = xml.createElement('params')
    params.setAttribute('alpha','7.5')
    params.setAttribute('delta','0.1')
    params.setAttribute('velocity','5')
    fb_susceptible.appendChild(params)
    #           </params>
    #       </fb_sir_diffusion_susceptible_controller>

    #       <fb_sir_diffusion_infected_controller>
    fb_infected = xml.createElement('fb_sir_diffusion_infected_controller')
    fb_infected.setAttribute('id','fdc_i')
    fb_infected.setAttribute('library','build/controllers/SIR_diffusion/libSIR_diffusion.so')
    controllers.appendChild(fb_infected)

    #           <actuators>
    actuators = xml.createElement('actuators')
    fb_infected.appendChild(actuators)

    #               <differential_steering>
    dif_steering = xml.createElement('differential_steering')
    dif_steering.setAttribute('implementation','default')
    actuators.appendChild(dif_steering)

    #               <leds>
    leds = xml.createElement('leds')
    leds.setAttribute('implementation','default')
    leds.setAttribute('medium','leds')
    actuators.appendChild(leds)
    #           </actuators

    #           <sensors>
    sensors = xml.createElement('sensors')
    fb_infected.appendChild(sensors)

    #               <footbot_proximity>
    fb_prox = xml.createElement('footbot_proximity')
    fb_prox.setAttribute('implementation','default')
    sensors.appendChild(fb_prox)

    #               <colored_blob_omnidirectional_camera>
    blobcam = xml.createElement('colored_blob_omnidirectional_camera')
    blobcam.setAttribute('implementation','rot_z_only')
    blobcam.setAttribute('medium','leds')
    blobcam.setAttribute('show_rays','true')
    sensors.appendChild(blobcam)
    #           </sensors>

    #           <params>
    params = xml.createElement('params')
    params.setAttribute('alpha','7.5')
    params.setAttribute('delta','0.1')
    params.setAttribute('velocity','5')
    fb_infected.appendChild(params)
    #           </params>
    #       </fb_sir_diffusion_infected_controller>

    #   <arena>
    arena = xml.createElement('arena')
    arena.setAttribute('size','5,5,1')
    arena.setAttribute('center','0,0,0.5')
    argos_config.appendChild(arena)

    #       <box>
    wall_n = xml.createElement('box')
    wall_n.setAttribute('id','wall_north')
    wall_n.setAttribute('size','4,0.1,0.5')
    wall_n.setAttribute('movable','false')
    arena.appendChild(wall_n)

    #           <body>
    body_n = xml.createElement('box')
    body_n.setAttribute('position','0,2,0')
    body_n.setAttribute('orientation','0,0,0')
    wall_n.appendChild(body_n)

    #       <box>
    wall_s = xml.createElement('box')
    wall_s.setAttribute('id','wall_south')
    wall_s.setAttribute('size','4,0.1,0.5')
    wall_s.setAttribute('movable','false')
    arena.appendChild(wall_s)

    #           <body>
    body_s = xml.createElement('box')
    body_s.setAttribute('position','0,-2,0')
    body_s.setAttribute('orientation','0,0,0')
    wall_s.appendChild(body_s)

    #       <box>
    wall_e = xml.createElement('box')
    wall_e.setAttribute('id','wall_east')
    wall_e.setAttribute('size','0.1,4,0.5')
    wall_e.setAttribute('movable','false')
    arena.appendChild(wall_e)

    #           <body>
    body_e = xml.createElement('box')
    body_e.setAttribute('position','2,0,0')
    body_e.setAttribute('orientation','0,0,0')
    wall_e.appendChild(body_e)

    #       <box>
    wall_w = xml.createElement('box')
    wall_w.setAttribute('id','wall_west')
    wall_w.setAttribute('size','0.1,4,0.5')
    wall_w.setAttribute('movable','false')
    arena.appendChild(wall_w)

    #           <body>
    body_w = xml.createElement('box')
    body_w.setAttribute('position','-2,0,0')
    body_w.setAttribute('orientation','0,0,0')
    wall_w.appendChild(body_w)

    ##############################################################
    # WE SPAWN IN BOTS HERE, RANDOMLY SELECTING ONE TO BE INFECTED
    ##############################################################

    #   </arena>

    #   <physics_engines>
    physics_eng = xml.createElement('physics_engines')
    argos_config.appendChild(physics_eng)

    #       <dynamics2d>
    dynamics = xml.createElement('dynamics2d')
    dynamics.setAttribute('id','dyn2d')
    physics_eng.appendChild(dynamics)
    #   </physics_engines>

    #   <media>
    media = xml.createElement('media')
    argos_config.appendChild(media)

    #       <led>
    leds = xml.createElement('led')
    leds.setAttribute('id','leds')
    media.appendChild(leds)
    #   </media>

    #   <visualization>
    visualization = xml.createElement('visualization')
    argos_config.appendChild(visualization)

    #       <qt-opengl>
    qt = xml.createElement('qt-opengl')
    visualization.appendChild(qt)

    #           <camera>
    camera = xml.createElement('camera')
    qt.appendChild(camera)

    #               <placements>
    placements = xml.createElement('placements')
    camera.appendChild(placements)

    #                   <placement>
    placement = xml.createElement('placement')
    placement.setAttribute('index','0')
    placement.setAttribute('position','0,0,13')
    placement.setAttribute('look_at','0,0,0')
    placement.setAttribute('up','1,0,0')
    placement.setAttribute('lens_focal_length','65')
    placements.appendChild(placement)
    #               </placements>
    #           </camera>
    #       </qt-opengl>
    #   </visualization>

    # </argos-configuration>







    xml_str = xml.toprettyxml(indent = "\t")

    save_path_file = "SIR_sim.xml"

    with open(save_path_file, "w") as f:
        f.write(xml_str)

if __name__ == "__main__":
    createXML()