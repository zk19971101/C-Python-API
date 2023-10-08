from distutils.core import setup, Extension
 
setup(name="sample", 
      ext_modules=[
        Extension("sample",# 包的名字
                  ["./myadd.cpp", "pysample.cpp"],
                  
                  )
        ]
)