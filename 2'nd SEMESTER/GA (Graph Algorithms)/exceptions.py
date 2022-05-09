class InvalidVertexError(Exception):
    pass

class InvalidStartVertexError(Exception):
    pass

class InvalidEndVertexError(Exception):
    pass

class ZeroInboundEdgesError(Exception):
    pass

class ZeroOutboundEdgesError(Exception):
    pass

class EdgeAlreadyExistsError(Exception):
    pass

class EdgeDoesNotExistError(Exception):
    pass

class InvalidNrVerEdgError(Exception):
    pass

class InvalidLineError(Exception):
    pass

class NeativeCycleError(Exception):
    pass

class GraphNotDAG(Exception):
    pass