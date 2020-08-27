cc_library(
    name = "core",
    srcs = ["core.cpp"],
    hdrs = [
        "core.h",
        "strings_gb2312.h",
        "strings_utf8.h",
    ],
)

cc_binary(
    name = "core_test",
    srcs = ["core_test.cpp"],
    deps = [
        ":core",
    ],
)
