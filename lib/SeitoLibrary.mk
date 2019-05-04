##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SeitoLibrary
ConfigurationName      :=Debug
WorkspacePath          :=D:/Users/namdx1987/Alldata/projects/cpp
ProjectPath            :=D:/Users/namdx1987/Alldata/projects/cpp/seitolibrary
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=namdx1987
Date                   :=30/04/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/raylib/mingw/bin/g++.exe
SharedObjectLinkerName :=C:/raylib/mingw/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SeitoLibrary.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/raylib/mingw/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/raylib/mingw/bin/ar.exe rcu
CXX      := C:/raylib/mingw/bin/g++.exe
CC       := C:/raylib/mingw/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/raylib/mingw/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/BookTitle.cpp$(ObjectSuffix) $(IntermediateDirectory)/LibraryContext.cpp$(ObjectSuffix) $(IntermediateDirectory)/BookCopy.cpp$(ObjectSuffix) $(IntermediateDirectory)/Student.cpp$(ObjectSuffix) $(IntermediateDirectory)/Manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/BorrowLog.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Users/namdx1987/Alldata/projects/cpp/seitolibrary/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/BookTitle.cpp$(ObjectSuffix): BookTitle.cpp $(IntermediateDirectory)/BookTitle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Users/namdx1987/Alldata/projects/cpp/seitolibrary/BookTitle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BookTitle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BookTitle.cpp$(DependSuffix): BookTitle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BookTitle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BookTitle.cpp$(DependSuffix) -MM BookTitle.cpp

$(IntermediateDirectory)/BookTitle.cpp$(PreprocessSuffix): BookTitle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BookTitle.cpp$(PreprocessSuffix) BookTitle.cpp

$(IntermediateDirectory)/LibraryContext.cpp$(ObjectSuffix): LibraryContext.cpp $(IntermediateDirectory)/LibraryContext.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Users/namdx1987/Alldata/projects/cpp/seitolibrary/LibraryContext.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LibraryContext.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LibraryContext.cpp$(DependSuffix): LibraryContext.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LibraryContext.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LibraryContext.cpp$(DependSuffix) -MM LibraryContext.cpp

$(IntermediateDirectory)/LibraryContext.cpp$(PreprocessSuffix): LibraryContext.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LibraryContext.cpp$(PreprocessSuffix) LibraryContext.cpp

$(IntermediateDirectory)/BookCopy.cpp$(ObjectSuffix): BookCopy.cpp $(IntermediateDirectory)/BookCopy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Users/namdx1987/Alldata/projects/cpp/seitolibrary/BookCopy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BookCopy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BookCopy.cpp$(DependSuffix): BookCopy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BookCopy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BookCopy.cpp$(DependSuffix) -MM BookCopy.cpp

$(IntermediateDirectory)/BookCopy.cpp$(PreprocessSuffix): BookCopy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BookCopy.cpp$(PreprocessSuffix) BookCopy.cpp

$(IntermediateDirectory)/Student.cpp$(ObjectSuffix): Student.cpp $(IntermediateDirectory)/Student.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Users/namdx1987/Alldata/projects/cpp/seitolibrary/Student.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Student.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Student.cpp$(DependSuffix): Student.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Student.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Student.cpp$(DependSuffix) -MM Student.cpp

$(IntermediateDirectory)/Student.cpp$(PreprocessSuffix): Student.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Student.cpp$(PreprocessSuffix) Student.cpp

$(IntermediateDirectory)/Manager.cpp$(ObjectSuffix): Manager.cpp $(IntermediateDirectory)/Manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Users/namdx1987/Alldata/projects/cpp/seitolibrary/Manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Manager.cpp$(DependSuffix): Manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Manager.cpp$(DependSuffix) -MM Manager.cpp

$(IntermediateDirectory)/Manager.cpp$(PreprocessSuffix): Manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Manager.cpp$(PreprocessSuffix) Manager.cpp

$(IntermediateDirectory)/BorrowLog.cpp$(ObjectSuffix): BorrowLog.cpp $(IntermediateDirectory)/BorrowLog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Users/namdx1987/Alldata/projects/cpp/seitolibrary/BorrowLog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BorrowLog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BorrowLog.cpp$(DependSuffix): BorrowLog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BorrowLog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BorrowLog.cpp$(DependSuffix) -MM BorrowLog.cpp

$(IntermediateDirectory)/BorrowLog.cpp$(PreprocessSuffix): BorrowLog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BorrowLog.cpp$(PreprocessSuffix) BorrowLog.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


