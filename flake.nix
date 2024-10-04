{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
  let
    matlab_math_overlay = final: prev: {
      matlab_math = final.callPackage ./default.nix { };
    };
    my_overlays = [ matlab_math_overlay ];
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default ];
    };
  in
  {
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

    packages.x86_64-linux =
      rec {
        matlab_math = pkgs.matlab_math;
        default = matlab_math;
      };
  };

}
