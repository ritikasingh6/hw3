#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> vec;
	int mary;
	PComparator compare;
	void trickleDown(int loc);




};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): mary(m), compare(c){

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int loc){
	int vecs = (int)vec.size();
	int child = mary*loc + 1;

	if (child > (vecs - 1)){
		return;
	}
	else{
		for (int i = 2; i <= mary; i++){
			if (mary *loc + i < vecs){
				int currChild = mary * loc + i;
				if (compare(vec[currChild],vec[child]) == true){
					child = currChild;
				}
			}
		}
		if (compare(vec[child],vec[loc]) == true){
			T temp = vec[child];
			vec[child] = vec[loc];
			vec[loc] = temp;
			trickleDown(child);
		}
	}
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
	
	vec.push_back(item);
	int vecInt = int(vec.size());
  int curr = vecInt - 1;
  int parent = (curr - 1)/mary;
  while((compare(vec[curr], vec[parent]) == true)&& curr != 0){
		std::swap(vec[parent], vec[curr]);
		curr = parent;
		parent = (curr - 1)/mary;
  }
	
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	return vec.std::vector<T>::empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
	return vec.std::vector<T>::size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw (std::underflow_error("Empty Heap"));


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return vec[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw (std::underflow_error("Empty Heap"));


  }
	vec[0] = vec.back();
	vec.pop_back();
	trickleDown(0);



}



#endif

