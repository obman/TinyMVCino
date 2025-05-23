#pragma once

// Helper macros to register/retrieve services more cleanly
#define FLYLAB_REGISTER_SERVICE(container, Type, instance) \
  (container).registerService<Type>(instance)

#define FLYLAB_GET_SERVICE(container, Type) \
  (container).getService<Type>()