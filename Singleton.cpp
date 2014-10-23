using namespace std;

class Foo{};

/* Place holder for thread synchronization lock */
class Lock {
public:
	Lock() { /* placeholder code to create the lock */ }
	~Lock() { /* placeholder code to deallocate the lock */ }
	void AcquireLock() { /* placeholder to acquire the lock */ }
	void ReleaseLock() { /* placeholder to release the lock */ }
};

/* Singleton class with a method that creates a new instance of the
 * class of the type of the passed in template if it does not
 * already exist. */
template <class T> 
class Singleton {
private:
	static Lock lock;
	static T* object;
private:
	Singleton();
	Singleton(const Singleton&);
	Singleton operator = (const Singleton&);
public:
	static T* getInstance();
};

template <class T> 
T* Singleton<T>::object = nullptr;

template <class T> 
Lock Singleton<T>::lock;

template <class T> 
T* Singleton<T>::getInstance(){
	if (object == nullptr) {  /* if object is not initialized, acquire lock */
		/* If two threads simultaneously check and pass the first “if”condition, 
		then only the one who acquired the lock first should create the instance */
		lock.AcquireLock(); 
		if(object == nullptr){ 
			object = new T;
		}
		lock.ReleaseLock();
	}
	return object;
}


int main(){
	// Foo is any class defined for which we want singleton access 
	Foo* singleton_foo = Singleton<Foo>::getInstance();
	return 0;
}
