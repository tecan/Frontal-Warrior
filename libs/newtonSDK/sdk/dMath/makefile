#*******************************************************
# Newton game dynamics 
# copy right by Julio Jerez 2002 - 2005 
#
#*******************************************************
#
# Generic makefile 
# this make file generate the libraries: 
# dg, physics, and newton
#
#*******************************************************  


# ******************************************************
#
# low level library
#
# ******************************************************
LIB_NAME = libdMath.a

INCLUDED_PATH = .
SRC_PATH = .

LIB_SRCS = \
	$(SRC_PATH)/dMathDefines.cpp \
	$(SRC_PATH)/dMatrix.cpp \
	$(SRC_PATH)/dQuaternion.cpp 	

# ******************************************************
#
# Allsource files
#
# ******************************************************
ALL_SRC_FILES = $(LIB_SRCS) 
DG_OBJ_FILES = $(ALL_SRC_FILES:.cpp=.o)

COMPILER = gcc

# Linux options	 gcc 4.2.2
CPU_FLAGS = -fPIC -O2 -msse  -msse2 -ffloat-store -ffast-math -freciprocal-math -funsafe-math-optimizations -fsingle-precision-constant 
FLAGS = -c -Wall -Wno-strict-aliasing -D_LINUX_VER  $(CPU_FLAGS) -I$(INCLUDED_PATH) 


.SUFFIXES : .o .cpp
.cpp.o :
	$(COMPILER) $(FLAGS) -o $@ $<	


# libraries targets
libTemp.a : $(DG_OBJ_FILES)
	ar r $@ $?
	strip -g -S -d -v $@  -o$@ 
	cp $@ ../$(LIB_NAME) 	
	
	#gcc -shared -Wl,-soname,libNewton.so $? -o libNewton.so 
	#cp libNewton.so ../newtonSDK/sdk/libNewton.so
	#sudo cp libNewton.so /usr/lib


# clean all objects target
clean :
	rm $(DG_OBJ_FILES)
	touch $(ALL_SRC_FILES)
#	rm -*.a

 

	
