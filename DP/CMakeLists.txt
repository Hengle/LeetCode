aux_source_directory(. SRC_FILES)
get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
foreach(arg ${SRC_FILES})
    get_filename_component(basename ${arg} NAME_WE) 
    add_executable(${basename} ${arg})
    set_target_properties(${basename} PROPERTIES FOLDER ${dirname})
endforeach()

