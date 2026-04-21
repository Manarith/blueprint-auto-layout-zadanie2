include("C:/blueprint-auto-layout-zadanie2/build/Desktop_Qt_6_11_0_MinGW_64_bit-Debugowa/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/blueprint-auto-layout-zadanie2-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "C:/blueprint-auto-layout-zadanie2/build/Desktop_Qt_6_11_0_MinGW_64_bit-Debugowa/blueprint-auto-layout-zadanie2.exe"
    GENERATE_QT_CONF
)
