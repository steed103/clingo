# [[[source: .
set(ide_source_group "Source Files")
set(source-group
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cc")
source_group("${ide_source_group}" FILES ${source-group})
set(source
    ${source-group})
# ]]]

add_executable(reify ${header} ${source})
target_link_libraries(reify PRIVATE libreify libpotassco)
target_include_directories(reify PRIVATE
    "$<BUILD_INTERFACE:${CLINGO_SOURCE_DIR}/libclingo>")
set_target_properties(reify PROPERTIES FOLDER exe)

install(TARGETS reify RUNTIME DESTINATION bin)
