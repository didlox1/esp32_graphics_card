class ITickable {
public:
    virtual ~ITickable() = default;
    //For computing state changes
    virtual void evaluate() = 0;
    //For applying state changes
    virtual void commit() = 0;
};