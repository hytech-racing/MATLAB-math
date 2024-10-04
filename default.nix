{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "matlab_math";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ ];
}