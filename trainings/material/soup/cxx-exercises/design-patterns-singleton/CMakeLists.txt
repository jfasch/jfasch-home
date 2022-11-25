ADD_EXECUTABLE(
  singleton-social-insurance-inflexible-main

  singleton-social-insurance-inflexible-main.cpp

  social-insurance-inflexible.h
  social-insurance-inflexible.cpp
)

ADD_EXECUTABLE(
  singleton-social-insurance-flexible-main

  singleton-social-insurance-flexible-main.cpp

  social-insurance-flexible.h
  social-insurance-flexible.cpp

  social-insurance-oegk.h
  social-insurance-oegk.cpp

  social-insurance-svs.h
  social-insurance-svs.cpp
)

ADD_EXECUTABLE(
  singleton-social-insurance-flexible-strict-main

  singleton-social-insurance-flexible-strict-main.cpp

  social-insurance-flexible-strict.h
  social-insurance-flexible-strict.cpp

  social-insurance-oegk-strict.h
  social-insurance-oegk-strict.cpp

  social-insurance-svs-strict.h
  social-insurance-svs-strict.cpp
)
