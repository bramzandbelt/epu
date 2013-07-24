MATLAB="/Applications/MATLAB_R2011b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/bram/.matlab/R2011b"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for epu_align_to_event" > epu_align_to_event_mex.mki
echo "CC=$CC" >> epu_align_to_event_mex.mki
echo "CFLAGS=$CFLAGS" >> epu_align_to_event_mex.mki
echo "CLIBS=$CLIBS" >> epu_align_to_event_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> epu_align_to_event_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> epu_align_to_event_mex.mki
echo "CXX=$CXX" >> epu_align_to_event_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> epu_align_to_event_mex.mki
echo "CXXLIBS=$CXXLIBS" >> epu_align_to_event_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> epu_align_to_event_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> epu_align_to_event_mex.mki
echo "LD=$LD" >> epu_align_to_event_mex.mki
echo "LDFLAGS=$LDFLAGS" >> epu_align_to_event_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> epu_align_to_event_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> epu_align_to_event_mex.mki
echo "Arch=$Arch" >> epu_align_to_event_mex.mki
echo OMPFLAGS= >> epu_align_to_event_mex.mki
echo OMPLINKFLAGS= >> epu_align_to_event_mex.mki
echo "EMC_COMPILER=unix" >> epu_align_to_event_mex.mki
echo "EMC_CONFIG=optim" >> epu_align_to_event_mex.mki
"/Applications/MATLAB_R2011b.app/bin/maci64/gmake" -B -f epu_align_to_event_mex.mk
