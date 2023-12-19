Peer to peer chat

Using a defined protocol

• !hello <name> - initialize a connection if not present
– first read message should be !ack
• this acks that the connection was established successfully
– if that line is not present - close the connection
• !bye - close connection
• !byebye - close all connections and exit

Today’s task - Peer to peer chat

• Choose an implementation (for the specified protocol):

– Usage of an existing messaging library
• Easier
• Max points: 85% * 20 points
• Eg: RabbitMQ, ActiveMQ

– Usage of vanilla Java: network sockets
• More challenging
• Max points: 100% * 20 points
• Eg: ServerSocket

Today’s task - Peer to peer chat

• Things to consider
– Communication between threads (application of thread pools)
• Message reader thread/task
• Message sender thread/task

– Have a connection manager (thread)

– Consider scenarios when a sender thread closes the connection but
the reader thread still reads data (shared data)
• handle exceptions
• closing connections - all from multiple threads

– This assignment is all about concurrency

Today’s task - Peer to peer chat

• Things to consider
– The above proposed protocol can be implemented in
various ways:
• Raw strings
• JSON (brings bonus points
• Protobufs (brings bonus points)
• Other communication protocols (brings bonus points)
