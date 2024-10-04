{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    easy_cmake.url = "github:RCMast3r/easy_cmake";
  };

  outputs = { self, nixpkgs, easy_cmake }: 
  let
    main_overlay = final: prev: {
      main = final.callPackage ./default.nix { };
    };
    my_overlays = [ main_overlay ];
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default ];
    };
  in
  {
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

    packages.x86_64-linux =
      rec {
        main = pkgs.main;
        default = main;
      };
  };

}
