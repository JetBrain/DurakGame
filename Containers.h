//#define uint unsigned int 
 template <typename T> class Node
{
 template <typename>
 friend class Queue;

 template <typename>
 friend class Stack;

 protected:
           Node<T>* next;
           Node<T>* back;
           T element;
 public:
           Node(Node<T>* = 0,Node<T>* = 0,T = 0);
           Node(const Node<T>&);
}; 

template <typename T>
class Queue
{
  protected:
            Node<T>* head;
            Node<T>* tale;
            int lenght;
  public:
            Queue(uint=0);
            T pop();
            void put(T);
            int getLen();
            void add(uint,T);
            void del(uint);
			      void swap(uint, uint);
            T& operator [](uint); 
            bool isEmpty();
            Node<T>* getElementByIndex(uint);
            bool containsLastNode();
};

template <typename T>
class Stack : public Queue<T>
{
public:
	Stack(uint = 0);
	T pop();
};

template <typename T>
Node<T>::Node(Node<T>* ptr_back,Node<T>* ptr_next,T value)
:next(ptr_next), back(ptr_back), element(value)
{}

template <typename T>
Node<T>::Node(const Node<T>& node):
next(node.next),back(node.back),element(node.element)
{}

template <typename T>
Queue<T>::Queue(uint size):head(0),tale(0),lenght(0)
{
  for(uint i = 0;i<size;i++)
  {
    this->put(T());
  }
}

template <typename T>
void Queue<T>::put(T value)
{
  if(isEmpty())
  {
     tale = new Node<T>(0,0,value);
     head = tale;
  }
  else
  {
     tale -> next = new Node<T>(tale,0,value);
     tale = tale -> next;
  }
  
  lenght++;
}
  
template <typename T>
T Queue<T>::pop()
{
  T temp;
    
  if(containsLastNode())
  {
    temp = head -> element;
    delete head;
    tale = 0;  
    head = 0;
  }
  else if(isEmpty())
  {
    throw "List is empty";
  } 
  else    
  {
    temp = head -> element;
    (head -> next)-> back = 0;
    Node<T>* tmp = head -> next;
    delete head;
    head = tmp;
  }

  lenght--;
  return temp;
}
  
template <typename T>
Node<T>* Queue<T>::getElementByIndex(uint i)
{
    if(i<=lenght)
    {
      Node<T>* tmp = head;
      for(;i>0;i--)
      {
        tmp = tmp -> next;
      }
      return tmp;
    }
    else
    {
      throw "Bad index!";
    }
  }

template <typename T> 
T& Queue<T>::operator [](uint i)
{
  return getElementByIndex(i) -> element;
}

template <typename T>
void Queue<T>::add(uint index,T el)
{
  Node<T>* tmp = getElementByIndex(index);
  if(tmp == head)
  {
    Node<T>* new_node = new Node<T>(0,tmp,el);
    tmp -> back = new_node;
    head = new_node;
  }
  else if(tmp == tale)
  {
    Node<T>* new_node = new Node<T>(tmp,0,el);
    tmp->next = new_node;
    tale = new_node;
  }
  else
  { 
    Node<T>* next_node = tmp -> next;
    Node<T>* new_node = new Node<T>(tmp,next_node,el);
    next_node -> back = new_node;
    tmp -> next = new_node;
  }

  lenght++;
}

template <typename T>
void Queue<T>::del(uint i)
{
  Node<T>* tmp = getElementByIndex(i);
  if(tmp == head)
  {
    tmp->next->back=0;
    head = tmp -> next;
  }
  else if(tmp == tale)
  {
    tmp->back->next=0;
    tale = tmp -> back;
  }
  else
  {
    Node<T>* back_node = tmp -> back;
    Node<T>* next_node = tmp -> next;
    back_node -> next = next_node;
    next_node -> back = back_node;
  }
  delete tmp;
  lenght--;
}

template <typename T>
void Queue<T>::swap(uint i, uint j)
{
	T tmp = (*this)[i];
	(*this)[i] = (*this)[j];
	(*this)[j] = tmp;
}

template <typename T>
int Queue<T>::getLen()
{
  return lenght;
}

template <typename T>
bool Queue<T>::containsLastNode()
{
  return tale == head && !isEmpty();
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return head == 0 && tale == 0;
}

template <typename T>
Stack<T>::Stack(uint size) : Queue<T>(size){}

template <typename T>
T Stack<T>::pop()
{
	T temp;

	if (this->containsLastNode())
	{
		temp = this -> tale -> element;
		delete this -> tale;
		this -> tale = 0;
		this -> head = 0;
	}
	else if (this -> isEmpty())
	{
		throw "List is empty";
	}
	else
	{
		temp = this -> tale -> element;
		(this -> tale -> back) -> next = 0;
		Node<T>* tmp = this -> tale -> back;
		delete this -> tale;
		this -> tale = tmp;
	}

	this -> lenght--;
	return temp;
}