CXX = g++-11 # try g++ or clang if it doesnt work 
CXXFLAGS = -std=c++20 -Wall -MMD -O2 -Werror=vla
SOURCES = $(wildcard *.cc)   # list of all .cc files in the current directory
OBJECTS = ${SOURCES:.cc=.o}  # .o files depend upon .cc files with same names
DEPENDS = ${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
EXEC = biquadris

# took this from A4 q1q2, need to change the flags 
${EXEC}: ${OBJECTS}
	# ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} # for textdisplay 
	 ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 # for graphicdisplay

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}