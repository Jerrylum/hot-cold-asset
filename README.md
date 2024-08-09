# Hot Cold Asset

## Introduction

The Hot Cold Asset solution is designed to embed to PROS 4 library projects. It allows users to embed regular files into PROS program binaries.

## Setup

To integrate the Hot Cold Asset solution into your PROS project, copy the following files from the `hot-cold-asset-repo` to your project:

- `firmware/hot-cold-asset.mk`
- `include/asset.h`

The `hot-cold-asset.mk` file contains the build rules for the asset files. The `asset.h` file contains the function prototypes for the asset functions.

## Explanation

### Asset

An asset is a regular file that is embedded into the PROS program binary. It can be an image file such as a gif, a text file, or any other file that you wish to access byte-by-byte during the execution of the program.

Before using "Hot Cold Asset", you need to convert the file to a C array, store it in a header file, and include the header file in your project. "Hot Cold Asset" simplifies this process by providing a set of build rules to automate the inclusion of the asset files.

You can include the asset files in your project by adding the asset files to the `static` or `static.lib` directories. Then, define the asset using the `ASSET` and `ASSET_LIB` macros. After that, use `.buf` to access the asset data and `.size` to access the asset size.

### Asset Management

Assets are stored in two separate directories: `static` and `static.lib`. This is helpful when developing library project that needs to include assets in the library binary and provide example assets for the user. The `hot-cold-asset.mk` makefile includes rules for compiling these assets into the project build.

- User-space Assets: Located in the `static` directory for development and usage in PROS projects. It is used to store assets that are accessible during the development of the library and during the use of the library in a PROS project. Files in this directory are not included in the library binary. However, they are included in the template zip file. These files are accessible by using the `ASSET` macro and can be used as example files.
- Library Assets: Located in the `static.lib` directory for inclusion in the library binary. It is used to store assets that need to be included in the library binary, for example, an image file displayed on the screen by the library. These files are accessible by using the `ASSET_LIB` macro.

## Example

The `hot-cold-asset-repo` folder is a project that demonstrates the "Hot Cold Asset" functionality. it is a library that allows you to display a gif image on the V5 Brain screen. It contains a gif file (the asset) that needs to be included in the library binary and the asset is stored in the `static.lib` folder.

In addition, the `hot-cold-asset-repo` project also contains a gif image that needs to be accessible both during the development of the library and during the use of the library in a PROS project. This file is stored in the `static` folder. It can be used as an example file, so it is also shipped in the template zip file.

The `hot-cold-asset-downstream` folder is a PROS project that uses the `hot-cold-asset-repo` library. After applying the `hot-cold-asset-repo` template to the PROS project, you can see the `static` folder in the project directory. This folder contains the gif image that is used as an example. In the main.cpp file, user space, and library assets are accessible using the `ASSET` and `ASSET_LIB` macros.
