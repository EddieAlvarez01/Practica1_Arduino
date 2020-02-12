#include "obstacle_list.h"

Obstacle_List::Obstacle_List()
{
  first = nullptr;
}

bool Obstacle_List::isEmpty(){
  if(first == nullptr){
    return true;
  }
  return false;  
}

void Obstacle_List::insert(Point p1){
  Obstacle_node *newNode = new Obstacle_node(p1);
  if(first != nullptr){
    Obstacle_node *tmp = first;
    while(tmp != nullptr){
      if(tmp->next == nullptr){
        tmp->next = newNode;
        break;
      }
      tmp = tmp->next;
    }
  }else{
    first = newNode;
  }
}

bool Obstacle_List::checkCollision(Car car){
  if(first != nullptr){
    Obstacle_node *tmp = first;
    while(tmp != nullptr){
      if((tmp->a.y == car.p1.x && tmp->a.x == car.p1.y) || (tmp->a.y == car.p2.x && tmp->a.x == car.p2.y) || (tmp->a.y == car.p3.x && tmp->a.x == car.p3.y) || 
         (tmp->a.y == car.p4.x && tmp->a.x == car.p4.y) || (tmp->a.y == car.p5.x && tmp->a.x == car.p5.y)){
          return true;
      }
      tmp = tmp->next;
    }
  }
  return false;  
}

void Obstacle_List::checkObstacles(){
  if(first != nullptr){
    Obstacle_node *tmp = first;
    Obstacle_node *tmp2 = nullptr;
    while(tmp != nullptr){
        if(tmp->a.y > 15){
          if(tmp == first){
            first = tmp->next;
          }else if(tmp->next == nullptr){
            tmp2->next = nullptr;
          }else{
            tmp2->next = tmp->next;
          }
          break;
        }
      tmp2 = tmp;
      tmp = tmp->next;
    }
  }  
}

int Obstacle_List::totalObstacles(){
  if(first != nullptr){
    int count = 0;
    Obstacle_node *tmp = first;
    while(tmp != nullptr){
      count++;
      tmp = tmp->next;
    }
    return count;
  }
  return 0;
}

void Obstacle_List::cleanList(){
  first = nullptr;
}
