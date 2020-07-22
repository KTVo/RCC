
package linklist;

public class LinkList<T extends Object> {

    private Node head; //Points to start of the linked list
    private Node tail; //Points to the end of the linked list
    
    private int listCount = 0; //Keeps track of the number of elements
    
    //The Default Constructor - Creates an emtpy linked list
    public LinkList(){
        head = null;
        tail = null;
        listCount = 0;
    }
    
    //Adds a node with a specified element to the end of the list
    public void add(T dataValue){
        Node temp = new Node(dataValue); //Creates new node with a value inside of it
        
        //if head is null (first interation), it creates new node
        //and sets head node equal to newly created node with value in it
        //and sets the tail equal to the head after
        if(head == null){
            head = temp;
            tail = head;
        }else{
            tail.setNext(temp);
            tail = temp;
        }
        listCount++;
    }
    
    //Returns an element at a particular position
    public T get (int indexPosition){
        //Throws ERROR if index is less than 0
        if(indexPosition < 0){
            throw new IllegalArgumentException();
        }
        
        Node current = head.getNext();
        for(int i = 0; i < indexPosition; i++){
            if(current.getNext() == null){
                return null;
            }
            current = current.getNext();
        }
        return (T)current.getData();
    }
    
    //Returns the next node
    public Node getNext(){
        return next;
    }
    
    //Removes the node at a specified position in the list
    public boolean remove(int indexPosition){
        listCount--;
        return true;
    }
    
    //Prints out elements in the linked list
    public String toString(){
        Node current = head;
        String output "";
        while(current != null){
            output += "[" + current.getData() + "]";
            current = current.getNext();
        }
        return output;
    }
}

