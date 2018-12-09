#!/bin/bash
set -e
set -x

# Directories
export ESMF_DIR=$(pwd)/ESMF
export ESMADIR=$(pwd)/Shared
export FV_DIR=$(pwd)/FVdycoreCubed_GridComp
export ESMF_INSTALL_PREFIX=$(pwd)/esmf_install

export ESMF_BOPT=O
export ESMF_COMPILER=intel
export ESMF_COMM=openmpi
export ESMF_OS=Linux

export ESMF_INSTALL_LIBDIR=lib
export ESMF_INSTALL_BINDIR=bin
export ESMF_INSTALL_DOCDIR=doc
export ESMF_INSTALL_HEADERDIR=include
export ESMF_INSTALL_MODDIR=include

# Build ESMF
if [ ! -f esmf.install ]; then
	cd $ESMF_DIR
	make --no-print-directory
	make --no-print-directory install 
	touch esmf.install 
	cd ..
fi

# Build MAPL
if [ ! -f mapl.install ]; then
	cd $ESMADIR 
	make --no-print-directory install 
	touch mapl.install 
	cd ..
fi

