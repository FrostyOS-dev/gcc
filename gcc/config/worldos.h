#undef TARGET_WORLDOS
#define TARGET_WORLDOS 1

#undef LIB_SPEC
#define LIB_SPEC "-lc" /* link against C standard library */

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s crti.o%s crtbegin.o%s"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()          \
  do                                      \
    {                                     \
      builtin_define ("__worldos__");     \
      builtin_assert ("system=worldos");  \
    }                                     \
  while (0);

#undef STANDARD_STARTFILE_PREFIX
#define STANDARD_STARTFILE_PREFIX "/data/lib/"

#undef LINK_SPEC
#define LINK_SPEC "%{shared:-shared} %{static:-static} %{!shared: %{!static: %{rdynamic:-export-dynamic}}} -z max-page-size=4096"

