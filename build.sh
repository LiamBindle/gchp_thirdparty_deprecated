#!/bin/bash

source environment.rc
export ESMF_INSTALL_LIBDIR=lib
export ESMF_INSTALL_BINDIR=bin
export ESMF_INSTALL_DOCDIR=doc
export ESMF_INSTALL_HEADERDIR=include
export ESMF_INSTALL_MODDIR=include

if [ ! -f install/esmf.install ]; then
	cd $ESMF_DIR && make --no-print-directory && make --no-print-directory install && touch install/esmf.install && cd ..
fi

# Build and install FVDycore
if [ ! -f install/fvdycore.install ]; then
	cd $FV_DIR && make --no-print-directory install && touch install fvdycore.install && cd ..
fi
