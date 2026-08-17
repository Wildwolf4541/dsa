/*
    Class is a user-defined data-type and object is an instance of the class.

    Creation of object-> ClassName objname;
    Access properties of a class using (.) operator and for pointers using (->).

    Three Types of Access Modifiers-> Private, Public, Protected.
    - Private Variables and Functions can be accessed within the class only.
    - Public ones can be accessed Gloabally.
    - Protected ones can be accessed within class only but can be inherited as well.

    Getter → Read private data.
    Setter → Modify private data with validation.

    Empty class size → 1 byte.

    Static Object → Hero h;
    Dynamic Object → Hero *h = new Hero;
    
    Constructor
    - Auto-called on object creation.
    - Three Types of Constructors
        * Non-Parameterized Constructor
        * Parameterized Constructor
        * Copy Constructor -> Hero(Hero &obj)

    Destructor
    - Auto-called on object destruction for static object
    - Use of "delete" for Dynamic object.

    this → Pointer to current object. Stores the address of current object.
    Assignment Operator → a = b

    Shallow Copy → Shared memory.
    Deep Copy → Separate memory.

    Static Member → Shared by all objects.
    Static Function → Access only static members.

    Scope Resolution Operator (::) -> Access Anything Anywhere.
*/

/*
    1. Encapsulation-> Data hiding. 
        * Wrapping up data members and functions in a class.
        * Data hide -> security increase.
        * if we want we can make class Read-Only.
        * Better for unit testing.
    
    2. Inheritance-> Properties are copied from parent class to child class.
        * class {child name}: {access modifier} {parent name}
        * Private properties or functions can't be inherited in any case.
        * properted ones in public and protected cases are both protected.
        * Object of child class can access functions and properties of parent class as well.
        
        Types of Inheritance->
            - Single Inheritance-        A->B
            - Multi-level Inheritance-   A->B->C->D->E
            - Multiple Inheritance-      A-> B <-C
            - Hierarchical Inheritance-  A-> B and C, C-> D and E
            - Hybrid Inheritance- Combination of More than one type of inheritance.

        Inheritance Ambiguity-> Suppose A->B<-C. A and C have same named function (func).
            When B accesses func, it is ambiguous of which func to take(of A or C).
            Resolved by scope resolution operator-> obj.A::func();
            
    3. Polymorphism-> Many Forms. Like Male is a father, a son, a husband.
        Types of polymorphism->
            - Compile-time Polymorphism (Static)
                - Function Overloading- When there are multiple functions in a class with the same name but different parameters, these functions are overloaded.
                - Operator Overloading- like using + for add and concat. void operator+ (Hero &obj){};

            - Run-time Polymorphism (Dynamic) (Method Overriding)
                Method of child class overides that of parent class if implemented in child class.
                Rules-> depends on inheritance. func name and func arguments of parent and child method should be same. 
        
        Static binding occurs at compile time and is used for static, private, final methods and method overloading. 
        Dynamic binding occurs at runtime, is used in method overriding, and enables runtime polymorphism 
        by allowing the JVM to choose the method based on the actual object type.

    4. Abstraction-> Implementation hiding. Essential cheezein btado, poori kahani btane ki lod ni.
        * Done using classes.
        * Increases reusability of code.
        * Only you can make changes to your data or functions.
        * Security increase by hiding background details.
        * Avoids duplication of code.
*/

/*
SOLID Principles
    1. Single Responsibility Principle-> A class should have only one reason to change.
    2. Open/Closed Principle-> Software entities should be open for extension but closed for modification.
    3. Liskov Substitution Principle-> Objects of a superclass shall be replaceable with objects of its subclasses without breaking the application.
    4. Interface Segregation Principle-> Many client-specific interfaces are better than one general-purpose interface.
    5. Dependency Inversion Principle-> Depend on abstractions, not on concretions.
    Dependency Injection means Passing dependencies from outside instead of creating them inside the class.
*/

/*
Association
is a relationship where two independent objects are connected and can interact with each other.
Example: Teacher ↔ Student

Aggregation
is a weak HAS-A relationship where the child can exist independently of the parent.
Example: Company → Employee. Employee leaves company, company and employee still exist.

Composition
is a strong HAS-A (PART-OF) relationship where the child cannot exist without the parent.
Example: Car → Engine. Without Car there will be no use of engine.

Composition is preferred because it promotes loose coupling, flexibility, code reuse, and allows behavior to be changed without modifying the existing class hierarchy.
example- Bird, penguin no fly example.
*/

/*
PECS stands for Producer Extends(Reads Data) Consumer Super(Writes Data)
copy(List<? extends T> src, List<? super T> dest)
*/