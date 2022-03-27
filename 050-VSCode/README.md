# VSCode with C++ and Cmake

Just needs uncompressing the `.vscode.tbz` file and running 'x c' (execute config).

## Config

* Common settings are in File/Preferences/Settings/Font: "'Terminus (TTF)'" (include the single quotes), size: 24
* Settings are in .vscode/settings.json.
* Warning: settings are copied to ~/.config/Code/User/settings.json (will be overwritten!).
* Start the app with "code ." or just 'e'
* If VSCode asks for kits, scan for them and select "Unspecified: let CMake select.."

## Usage

* Below, on the status bar, click on "Build"
* Below, on the status bar, run with the right-pointing triangle (Run)
* Also, run with [CONTROL][F5]
* Format code with [CTRL][SHIFT][i]
* Snippets appear with [CTRL][SPACE]
* [CTRL][SHIFT][b] builds and runs using the tasks.json file and the `.x` script.
* [CTRL][p] opens the QuickOpen bar
* [CTRL][ALT][z] generates comments, if `ext install Hiyajo.cppcomment` has been installed.
