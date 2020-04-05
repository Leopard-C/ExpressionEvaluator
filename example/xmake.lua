
target("exp_ev")
    set_kind("binary")

    -- std=c++11
    set_languages("c99", "cxx11")

    -- source file
    add_files("expression_eval/*.cpp")
    add_files("../ExpressionEvaluator.cpp")

    -- target dir
    set_targetdir("expression_eval/")

    -- build dir
    set_objectdir("build/objs")

target("icalculator")
    set_kind("binary")

    -- std=c++11
    set_languages("c99", "cxx11")

    -- source file
    add_files("calculator/*.cpp")
    add_files("../ExpressionEvaluator.cpp")

    -- target dir
    set_targetdir("calculator/")

    -- build dir
    set_objectdir("build/objs")

