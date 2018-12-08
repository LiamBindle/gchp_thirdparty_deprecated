#!/bin/bash
export ESMF_DIR=$(pwd)/ESMF
export ESMF_BOPT=O
export ESMF_COMPILER=gfortran
export ESMF_COMM=openmpi
export ESMF_OS=Linux

export ESMF_INSTALL_PREFIX=$(pwd)/install
export ESMF_INSTALL_LIBDIR=lib
export ESMF_INSTALL_BINDIR=bin
export ESMF_INSTALL_DOCDIR=doc
export ESMF_INSTALL_HEADERDIR=include
export ESMF_INSTALL_MODDIR=include
