include_directories(${ARGOS_QTOPENGL_INCLUDE_DIRS})

add_library(SIR_loop_functions MODULE 
    SIR_loop_functions.h 
    SIR_loop_functions.cpp)

target_link_libraries(SIR_loop_functions
    argos3core_simulator
    argos3plugin_simulator_entities
    argos3plugin_simulator_footbot
    argos3plugin_simulator_qtopengl
    ${ARGOS_QTOPENGL_LIBRARIES})