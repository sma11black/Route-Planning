## Running

```
.\RoutePlanning.exe -f map.osm
```

## Debug and Launch settings

```
  "configurations": [
    {
      ...,
      "currentDir": "${workspaceRoot}",
      "args": [
        "-f",
        "map.osm"
      ]
    }
  ]
```

## VS CMake vcpkg

### vcpkg

[Dependency installation instructions](https://raw.githubusercontent.com/mikebmcl/P0267_RefImpl/D0267R7/P0267_RefImpl/P0267_RefImpl/win32/Dependency%20installation%20instructions.txt)

X86:
```
.\vcpkg.exe install cairo
.\vcpkg.exe install graphicsmagick
.\vcpkg.exe install io2d
.\vcpkg.exe list
.\vcpkg.exe install pugixml
```

X64:
```
.\vcpkg.exe install cairo --triplet x64-windows
```

### VS

CMakeSettings.json
```json
"configurations": [
    {
      ...,
      "variables": [
        {
          "name": "CMAKE_TOOLCHAIN_FILE",
          "value": "D:\\Workspace\\VisualStudioProjects\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake"
        }
      ]
    },
```

### io2d package BUG Fix

Error:

`D:\Workspace\VisualStudioProjects\vcpkg\installed\x86-windows\share\io2d\io2dTargets.cmake`

Solution:

line66: Cairo::Cairo => unofficial::cairo::cairo

### Other bug

Can't find CMake package => Use VS 2017 with English.
