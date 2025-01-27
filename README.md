
**This is an unofficial Flatpak version of Code::Blocks IDE that is not endorsed nor supported by its developer.**

Please open issues under: https://github.com/flathub/org.codeblocks.codeblocks/issues

This version is running inside a container and is therefore not able to access SDKs on your host system!  
This flatpak provides a standard development environment (gcc, python, etc).

* To see what's available:
  ```
  $ flatpak run --command=sh org.codeblocks.codeblocks
  $ ls /usr/bin (shared runtime)
  $ ls /app/bin (bundled with this flatpak)
  ```
* To get support for additional languages, you have to install SDK extensions, e.g.
  ```
  $ flatpak install flathub org.freedesktop.Sdk.Extension.dotnet
  $ flatpak install flathub org.freedesktop.Sdk.Extension.golang
  ```
* To enable selected extensions, set `FLATPAK_ENABLE_SDK_EXT` environment variable to a comma-separated list of
  extension names (name is ID portion after the last dot):
  ```
  $ FLATPAK_ENABLE_SDK_EXT=dotnet,golang flatpak run org.codeblocks.codeblocks
  ```
* To make this persistent, set the variable via flatpak override:
  ```
  $ flatpak override --user org.codeblocks.codeblocks --env=FLATPAK_ENABLE_SDK_EXT="dotnet,golang"
  ```
* You can use `$ flatpak search <TEXT>` to find others.

***
The Code::Blocks plugin contains:
- sfml2
- sfml3
- wxWidgets3
- raylib5
- fltk1

They are installed in /app/plugins/devtools/ with the structure:
```
├── bin
├── include
│   ├── FL
│   ├── GL
│   ├── GLFW
│   ├── SFML
│   │   ├── Audio
│   │   ├── Graphics
│   │   ├── Network
│   │   ├── System
│   │   └── Window
│   └── SFML2
│       └── SFML
├── lib
│   └── SFML2
│       ├── cmake
│       └── pkgconfig
├── lib64
│   ├── cmake
│   │   ├── glfw3
│   │   ├── raylib
│   │   └── SFML
│   └── pkgconfig

```

