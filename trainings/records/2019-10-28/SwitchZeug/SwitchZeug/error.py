class SwitchZeugError(Exception):
    def __init__(self, message):
        super().__init__(message)

class MichisError(SwitchZeugError):
    def __init__(self, message):
        super().__init__(message)
        
class InterfaceNameNotUnique(SwitchZeugError):
    def __init__(self, message):
        super().__init__(message)
        
