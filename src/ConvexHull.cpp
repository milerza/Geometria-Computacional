#include "ConvexHull.hpp"

std::vector<point> convexHull::giftWrapping(){
    std::vector<point> hull;

    int n = points.size();
    
    if(n < 3){
        return hull;
    }

    //encontra o ponto mais a esquerda
    int first = 0, p, q;

    for(int i = 0; i < n; i++){
        if(this->points[i].x < this->points[first].x) {
            first = i;
        }
    }

    // Do: Faça a envoltura em sentido anti-horário, 
    // While: enquanto não voltarmos pro ponto inicial;
    p = first;

    do {
        hull.push_back(points[p]);
        
        // q é o proximo ponto no vetor points, depois de p 
        q = (p + 1)% n;

        for (int i = 0; i < n;i++) {
            // Se o caminho p-> i -> q for no sentido anti-horário
            // então i envelopa q
            if(orientation(points[p], points[i], points[q]) == 2){
                q = i;
            }
        }

        p = q;

    } while (p != first);
    
    return hull;
}

int convexHull::orientation(point p1, point p2, point p3){
    int a = (p2.y - p1.y)*(p3.x - p2.x) - (p3.y - p2.y)*(p2.x - p1.x); 

    if (a == 0) return 0;
    else if (a > 0) return 1;
    else return 2; 
}