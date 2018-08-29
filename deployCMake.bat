@echo off
for /d  %%s in (*) do (
    if not "%%s" == ".vscode" (
        if not "%%s" == "Array" (
            if not "%%s" == "build" (
                if not "%%s" == "Java" (
                    copy  Array\CMakeLists.txt %%s
                )
            )
        )
    )
)