QT  += core gui widgets  charts ##datavisualization

requires(qtConfig(filedialog))
requires(qtConfig(treeview))



MKLDIR = $$(MKLROOT)
LIBS += -L$$MKLDIR/lib/intel64 -fopenmp -lmkl_gf_ilp64 -lmkl_gnu_thread
LIBS += -lmkl_core -Wl,-rpath,$$MKLDIR/lib/intel64

# OpenMP
#msvc {
#   QMAKE_CXXFLAGS += /openmp
#   QMAKE_LFLAGS += /openmp
#}
#!msvc {
#   QMAKE_CXXFLAGS += -fopenmp
#   QMAKE_LFLAGS += -fopenmp
#}


TARGET = HAO-Viewer
TEMPLATE = app

INCLUDEPATH += .
INCLUDEPATH    += /usr/local/include  /usr/local/include/vtk
DEPENDPATH     += /usr/local/include  /usr/local/include/vtk
LIBS += -L/usr/local/lib64 -L/usr/local/lib

MKLDIR = $$(MKLROOT)

LIBS +=  -fopenmp

LIBS += -L$$MKLDIR/lib/intel64 -lQtColorWidgets-Qt5 -fopenmp
LIBS += -lmkl_gf_ilp64 -lmkl_gnu_thread -lmkl_core -Wl,-rpath,$$MKLDIR/lib/intel64


CONFIG += c++11 fopenmp
CONFIG(win32, win32|macx){
    VTK_INCLUDE_DIR = D:\VTK\vtk\include\vtk-8.2
    VTK_LIB_DIR = D:\VTK\vtkOut\lib
    VTK_LIB_VER = 8.90
    VTK_LIB_PREFIX = $${VTK_LIB_VER}
    VTK_LIB_NAME =  vtkalglib\
                    vtkChartsCore\
                    vtkCommonColor\
                    vtkCommonComputationalGeometry\
                    vtkCommonCore\
                    vtkCommonDataModel\
                    vtkCommonExecutionModel\
                    vtkCommonMath\
                    vtkCommonMisc\
                    vtkCommonSystem\
                    vtkCommonTransforms\
                    vtkDICOMParser\
                    vtkDomainsChemistry\
                    vtkDomainsChemistryOpenGL2\
                    vtkFiltersAMR\
                    vtkFiltersCore\
                    vtkFiltersExtraction\
                    vtkFiltersFlowPaths\
                    vtkFiltersGeneral\
                    vtkFiltersGeneric\
                    vtkFiltersGeometry\
                    vtkFiltersHybrid\
                    vtkFiltersHyperTree\
                    vtkFiltersImaging\
                    vtkFiltersModeling\
                    vtkFiltersParallel\
                    vtkFiltersParallelImaging\
                    vtkFiltersPoints\
                    vtkFiltersProgrammable\
                    vtkFiltersSelection\
                    vtkFiltersSMP\
                    vtkFiltersSources\
                    vtkFiltersStatistics\
                    vtkFiltersTexture\
                    vtkFiltersTopology\
                    vtkFiltersVerdict\
                    vtkfreetype\
                    vtkGeovisCore\
                    vtkgl2ps\
                    vtkglew\
                    vtkhdf5_hl\
                    vtkhdf5\
                    vtkImagingColor\
                    vtkImagingCore\
                    vtkImagingFourier\
                    vtkImagingGeneral\
                    vtkImagingHybrid\
                    vtkImagingMath\
                    vtkImagingMorphological\
                    vtkImagingSources\
                    vtkImagingStatistics\
                    vtkImagingStencil\
                    vtkInfovisCore\
                    vtkInfovisLayout\
                    vtkInteractionImage\
                    vtkInteractionStyle\
                    vtkInteractionWidgets\
                    vtkIOAMR\
                    vtkIOCore\
                    vtkIOEnSight\
                    vtkIOExodus\
                    vtkIOExport\
                    vtkIOExportOpenGL2\
                    vtkIOGeometry\
                    vtkIOImage\
                    vtkIOImport\
                    vtkIOInfovis\
                    vtkIOLegacy\
                    vtkIOLSDyna\
                    vtkIOMINC\
                    vtkIOMovie\
                    vtkIONetCDF\
                    vtkIOParallel\
                    vtkIOParallelXML\
                    vtkIOPLY\
                    vtkIOSQL\
                    vtkIOTecplotTable\
                    vtkIOVideo\
                    vtkIOXML\
                    vtkIOXMLParser\
                    vtkjpeg\
                    vtkjsoncpp\
                    vtklibharu\
                    vtklibxml2\
                    vtklz4\
                    vtkmetaio\
                    #vtkNetCDF\
                    vtkParallelCore\
                    vtkpng\
                  # vtknetcdfcpp\
                   # vtkoggtheora\
                   # vtkproj4\
                 #   vtkexoIIc\
               #     vtkexpat\
                    vtkRenderingAnnotation\
                    vtkRenderingContext2D\
                    vtkRenderingContextOpenGL2\
                    vtkRenderingCore\
                    vtkRenderingFreeType\
                    vtkRenderingGL2PSOpenGL2\
                    vtkRenderingImage\
                    vtkRenderingLabel\
                    vtkRenderingLOD\
                    vtkRenderingOpenGL2\
                    vtkRenderingVolume\
                    vtkRenderingVolumeOpenGL2\
                    vtksqlite\
                    vtksys\
                    vtktiff\
                    vtkverdict\
                    vtkViewsContext2D\
                    vtkViewsCore\
                    vtkViewsInfovis\
                    vtkzlib
    for(lib,VTK_LIB_NAME){
        VTK_LIBS += -l$${lib}-$${VTK_LIB_PREFIX}
    }
    INCLUDEPATH += $${VTK_INCLUDE_DIR}
    DEPENDPATH += $${VTK_INCLUDE_DIR}
    LIBS += -L$${VTK_LIB_DIR} $${VTK_LIBS}
}
else{ #LINUX
    VTK_INCLUDE_DIR = /usr/local/include/vtk
    VTK_LIB_DIR = /usr/local/lib64
    VTK_LIB_VER = 8.2
    VTK_LIB_PREFIX = $${VTK_LIB_VER}
    VTK_LIB_NAME =  vtkChartsCore\
                    vtkCommonColor\
                    vtkCommonComputationalGeometry\
                    vtkCommonCore\
                    vtkCommonDataModel\
                    vtkCommonExecutionModel\
                    vtkCommonMath\
                    vtkCommonMisc\
                    vtkCommonSystem\
                    vtkCommonTransforms\
                    vtkDICOMParser\
                    vtkDomainsChemistry\
                    vtkDomainsChemistryOpenGL2\
                    vtkFiltersAMR\
                    vtkFiltersCore\
                    vtkFiltersExtraction\
                    vtkFiltersFlowPaths\
                    vtkFiltersGeneral\
                    vtkFiltersGeneric\
                    vtkFiltersGeometry\
                    vtkFiltersHybrid\
                    vtkFiltersHyperTree\
                    vtkFiltersImaging\
                    vtkFiltersModeling\
                    vtkFiltersParallel\
                    vtkFiltersParallelImaging\
                    vtkFiltersPoints\
                    vtkFiltersProgrammable\
                    vtkFiltersSMP\
                    vtkFiltersSelection\
                    vtkFiltersSources\
                    vtkFiltersStatistics\
                    vtkFiltersTexture\
                    vtkFiltersTopology\
                    vtkFiltersVerdict\
                    vtkGUISupportQt\
                    vtkGUISupportQtSQL\
                    vtkGeovisCore\
                    vtkIOAMR\
                    vtkIOCore\
                    vtkIOEnSight\
                    vtkIOExodus\
                    vtkIOExport\
                    vtkIOExportOpenGL2\
                    vtkIOGeometry\
                    vtkIOImage\
                    vtkIOImport\
                    vtkIOInfovis\
                    vtkIOLSDyna\
                    vtkIOLegacy\
                    vtkIOMINC\
                    vtkIOMovie\
                    #vtkIONetCDF\
                    vtkIOPLY\
                    vtkIOParallel\
                    vtkIOParallelXML\
                    vtkIOSQL\
                    vtkIOTecplotTable\
                    vtkIOVideo\
                    vtkIOXML\
                    vtkIOXMLParser\
                    vtkImagingColor\
                    vtkImagingCore\
                    vtkImagingFourier\
                    vtkImagingGeneral\
                    vtkImagingHybrid\
                    vtkImagingMath\
                    vtkImagingMorphological\
                    vtkImagingSources\
                    vtkImagingStatistics\
                    vtkImagingStencil\
                    vtkInfovisCore\
                    vtkInfovisLayout\
                    vtkInteractionImage\
                    vtkInteractionStyle\
                    vtkInteractionWidgets\
                    #vtkNetCDF\
                    vtkParallelCore\
                    vtkRenderingAnnotation\
                    vtkRenderingContext2D\
                    vtkRenderingContextOpenGL2\
                    vtkRenderingCore\
                    vtkRenderingFreeType\
                    vtkRenderingGL2PSOpenGL2\
                    vtkRenderingImage\
                    vtkRenderingLOD\
                    vtkRenderingLabel\
                    vtkRenderingOpenGL2\
                    vtkRenderingQt\
                    vtkRenderingVolume\
                    vtkRenderingVolumeOpenGL2\
                    vtkViewsContext2D\
                    vtkViewsCore\
                    vtkViewsInfovis\
                    vtkViewsQt\
                    vtkexpat\
                    vtkfreetype\
                    vtkgl2ps\
                    vtkglew\
                    vtkhdf5\
                    vtkhdf5_hl\
                    vtkjpeg\
                    vtkjsoncpp\
                    vtklibharu\
                    vtklibxml2\
                    vtklz4\
                    vtkmetaio\
                   # vtknetcdfcpp\
                   # vtkoggtheora\
                   # vtkalglib\
                   # vtkexoIIc\
                   # vtkproj4\
                   # vtkLocalExample\
                    vtkpng\
                    vtksqlite\
                    vtksys\
                    vtktiff\
                    vtkverdict\
                    vtkzlib
    for(lib,VTK_LIB_NAME){
        VTK_LIBS += -l$${lib}-$${VTK_LIB_PREFIX}
       # VTK_LIBS += -l$${lib}-$${VTK_LIB_PREFIX}.1
    }
    INCLUDEPATH += $${VTK_INCLUDE_DIR}
    DEPENDPATH += $${VTK_INCLUDE_DIR}
    LIBS += -L$${VTK_LIB_DIR} $${VTK_LIBS}
}






HEADERS       = mainwindow.h \
    Angular3D.h \
    Cloud3D.h \
    HAtomOrb.h \
    ShowMOForm.h \
    SolveEquation.h \
    matrix3/vector3.h \
    matrix3/matrix3x3.h \
    orbitalProperty.h \
    textEditor.h \
    FileTree.h \
    Mesh3D.h \
    View3D.h \
    RadialFunViewer.h \
    HMol.h
SOURCES       = main.cpp \
    Angular3D.cpp \
    Cloud3D.cpp \
    ShowMOForm.cpp \
    SolveEquation.cpp \
                mainwindow.cpp \
    HAtomOrb.cpp \
    matrix3/vector3.cpp \
    matrix3/matrix3x3.cpp \
    orbitalProperty.cpp \
    textEditor.cpp \
    FileTree.cpp \
    Mesh3D.cpp \
    View3D.cpp \
    RadialFunViewer.cpp \
    HMol.cpp





FORMS += \
    UI/AOProperty.ui \
    UI/MO.ui \
    UI/color_dialog.ui \
    UI/color_palette_widget.ui \
    UI/mainwindow.ui \




