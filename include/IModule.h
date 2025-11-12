class IModule {
public:
    virtual ~IModule() = default;
    virtual void print() = 0;
};