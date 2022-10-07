from xml.dom import minidom
import math
# import random
# import numpy as np

####### GLOBAL CONSTANTS (DON'T MODIFY) #######

H_C = 0.288699733
I_BOT = 'fdc_i'
S_BOT = 'fdc_s'

####### GLOBAL VARIABLES (CONFIGURABLE) #######

INFECTION_RANGE = 0.25      # in grid units
INFECTED_COUNT = 1          # number of initially infected bots
BOT_COUNT = 40              # not including INFECTED_COUNT
ARENA_SIZE = (10,10,1)      # (x,y,z)
CAM_HEIGHT = 35             # simulation camera height
TPS = 20                    # ticks/steps per second

############################################################


# generates arena size string for xml based on ARENA_SIZE
def arenaSize():
    return str(ARENA_SIZE[0])+','+str(ARENA_SIZE[1])+','+str(ARENA_SIZE[2])

# generates wall size string for each wall face based on ARENA_SIZE
def wallSize(face):
    if (face.lower() == 'north' or face.lower() == 'south'):
        return str(ARENA_SIZE[0])+',0.1,0.5'
    elif (face.lower() == 'east' or face.lower() == 'west'):
        return '0.1,'+str(ARENA_SIZE[1])+',0.5'
    else:
        raise Exception("ERROR: A valid wall name was not given...")

# generates wall position string for each wall face based on ARENA_SIZE
def wallPosition(face):
    if face.lower() == 'north':
        return '0,'+str(ARENA_SIZE[0]/2)+',0'
    elif face.lower() == 'south':
        return '0,-'+str(ARENA_SIZE[0]/2)+',0'
    elif face.lower() == 'east':
        return str(ARENA_SIZE[1]/2)+',0,0'
    elif face.lower() == 'west':
        return '-'+str(ARENA_SIZE[1]/2)+',0,0'
    else:
        raise Exception("ERROR: A valid wall name was not given...")

# for uniform distribution method based on ARENA_SIZE
def botUPosition(limit):
    if limit.lower() == 'min':
        return str(-ARENA_SIZE[0]/2)+','+str(-ARENA_SIZE[1]/2)+',0'
    elif limit.lower() == 'max':
        return str(ARENA_SIZE[0]/2)+','+str(ARENA_SIZE[1]/2)+',0'
    else:
        raise Exception("ERROR: limit name unidentified for botUPosition()")

# to get camera aperture from desired range using INFECTION_RANGE and H_C
def aperture():
    return str(math.degrees(math.atan2(INFECTION_RANGE,H_C)))

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
    experiment.setAttribute('ticks_per_second',str(TPS))
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
    arena.setAttribute('size',arenaSize())
    arena.setAttribute('center','0,0,0.5')
    argos_config.appendChild(arena)

    #       <box>
    wall_n = xml.createElement('box')
    wall_n.setAttribute('id','wall_north')
    wall_n.setAttribute('size',wallSize('north'))
    wall_n.setAttribute('movable','false')
    arena.appendChild(wall_n)

    #           <body>
    body_n = xml.createElement('body')
    body_n.setAttribute('position',wallPosition('north'))
    body_n.setAttribute('orientation','0,0,0')
    wall_n.appendChild(body_n)

    #       <box>
    wall_s = xml.createElement('box')
    wall_s.setAttribute('id','wall_south')
    wall_s.setAttribute('size',wallSize('south'))
    wall_s.setAttribute('movable','false')
    arena.appendChild(wall_s)

    #           <body>
    body_s = xml.createElement('body')
    body_s.setAttribute('position',wallPosition('south'))
    body_s.setAttribute('orientation','0,0,0')
    wall_s.appendChild(body_s)

    #       <box>
    wall_e = xml.createElement('box')
    wall_e.setAttribute('id','wall_east')
    wall_e.setAttribute('size',wallSize('east'))
    wall_e.setAttribute('movable','false')
    arena.appendChild(wall_e)

    #           <body>
    body_e = xml.createElement('body')
    body_e.setAttribute('position',wallPosition('east'))
    body_e.setAttribute('orientation','0,0,0')
    wall_e.appendChild(body_e)

    #       <box>
    wall_w = xml.createElement('box')
    wall_w.setAttribute('id','wall_west')
    wall_w.setAttribute('size',wallSize('west'))
    wall_w.setAttribute('movable','false')
    arena.appendChild(wall_w)

    #           <body>
    body_w = xml.createElement('body')
    body_w.setAttribute('position',wallPosition('west'))
    body_w.setAttribute('orientation','0,0,0')
    wall_w.appendChild(body_w)

    ################################################################
    # WE SPAWN IN BOTS HERE, SELECTING ONE TO BE INFECTED #
    ################################################################

    #       <distribute>
    distribute_sus = xml.createElement('distribute')
    arena.appendChild(distribute_sus)

    #           <position>
    position_sus = xml.createElement('position')
    position_sus.setAttribute('method','uniform')
    position_sus.setAttribute('min',botUPosition('min'))
    position_sus.setAttribute('max',botUPosition('max'))
    distribute_sus.appendChild(position_sus)

    #           <orientation>
    orient_sus = xml.createElement('orientation')
    orient_sus.setAttribute('method','gaussian')
    orient_sus.setAttribute('mean','0,0,0')
    orient_sus.setAttribute('std_dev','360,0,0')
    distribute_sus.appendChild(orient_sus)

    #           <entity>
    entity_sus = xml.createElement('entity')
    entity_sus.setAttribute('quantity', str(BOT_COUNT))
    entity_sus.setAttribute('max_trials','100')
    distribute_sus.appendChild(entity_sus)

    #               <foot-bot>
    footbot_S = xml.createElement('foot-bot')
    footbot_S.setAttribute('id','fb')
    footbot_S.setAttribute('omnidirectional_camera_aperture',aperture())
    entity_sus.appendChild(footbot_S)

    #                   <controller>
    cont_sus = xml.createElement('controller')
    cont_sus.setAttribute('config',S_BOT)
    footbot_S.appendChild(cont_sus)
    #                   </controller>
    #               </foot-bot>
    #           </entity>
    #       </distribute>

################  infected ###################

    #       <distribute>
    distribute_inf = xml.createElement('distribute')
    arena.appendChild(distribute_inf)

    #           <position>
    position_inf = xml.createElement('position')
    position_inf.setAttribute('method','uniform')
    position_inf.setAttribute('min',botUPosition('min'))
    position_inf.setAttribute('max',botUPosition('max'))
    distribute_inf.appendChild(position_inf)

    #           <orientation>
    orient_inf = xml.createElement('orientation')
    orient_inf.setAttribute('method','gaussian')
    orient_inf.setAttribute('mean','0,0,0')
    orient_inf.setAttribute('std_dev','360,0,0')
    distribute_inf.appendChild(orient_inf)

    #           <entity>
    entity_inf = xml.createElement('entity')
    entity_inf.setAttribute('quantity', str(INFECTED_COUNT))
    entity_inf.setAttribute('max_trials','100')
    distribute_inf.appendChild(entity_inf)

    #               <foot-bot>
    footbot_I = xml.createElement('foot-bot')
    footbot_I.setAttribute('id','fb_i')
    footbot_I.setAttribute('omnidirectional_camera_aperture',aperture())
    entity_inf.appendChild(footbot_I)

    #                   <controller>
    cont_inf = xml.createElement('controller')
    cont_inf.setAttribute('config',I_BOT)
    footbot_I.appendChild(cont_inf)
    #                   </controller>
    #               </foot-bot>
    #           </entity>
    #       </distribute>

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
    placement.setAttribute('lens_focal_length',str(CAM_HEIGHT))
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






# class Bot:
#     def __init__(self, id, config):
#         self.id = id
#         self.config = config
#         self.aperature = math.degrees(math.atan2(INFECTION_RANGE,H_C))
    
#     def set_position(self, position):
#         self.position = position

#     def set_orientation(self, orientation):
#         self.orientation = orientation

# def createBotList():

#     bot_list = []
#     for i in range(BOT_COUNT):
#         if i < BOT_COUNT-INFECTED_COUNT-1:
#             bot_list.append(Bot('fb'+str(i),S_BOT))
#         else:
#             bot_list.append(Bot('fb'+str(i),I_BOT))