# Bounce

### GLM Bug
After `apt install libglm-dev`, in `/lib/cmake/glm/glmConfig.cmake`, a change is necessary:

```
get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)
```
by:
```
get_filename_component(PACKAGE_PREFIX_DIR "/usr/" ABSOLUTE)
```
