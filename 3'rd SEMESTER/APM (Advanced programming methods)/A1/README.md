Assignment A1

Please choose one problem from the file examples.txt and implement it in
Java using the Model-View-Controler (MVC) architectural pattern as
follows:

1.1. Model: contains the classes which correspond to the problem entities.
Those classes can either form a hierarchy or implement the same interface.
If you choose the class hierarchy you must use the method overriding for
the method required to solve the problem. If you choose to implement the
same interface, that interface must contain the method required to solve
the problem. Please use an interface.

1.2. Repository: is a in-memory repository. Please use fixed size array to
implement the collection of the problem entities.

1.3. Controller: implements the functionality required by the problem and
the operations to add and remove entities from the repository. It maintains
a reference to the repository. The reference type is an interface such that
we can easily replace the repository implementation.

1.4. View: usually consists of an text interface with the following
functionalities: input an entity from the keyboard, delete an entity and the
main functionality which solve the problem. However in order to avoid
IO operations,the text interface is not compulsory for the maximum
grade. For the maximum grade you can also hardcode the test
examples inside the main method.

1.5. Please use exceptions to treat the errors.

1.6. Please use different packages to implement the repositoy, the model,
the controller and the view.
