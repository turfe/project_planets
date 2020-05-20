#include <SFML/Graphics.hpp>
#include <iostream>
#include "vector.h"
#include <vector>
#include <math.h>

using namespace std;

const double G = 6.67 * pow(10, -11);
const unsigned int N = 100;
const float dt = 0.05;
const unsigned int N_orbs = 1000;

class Point {
public:
    double m, r, x, y;
    Vector a, v;

    Point() {};

    ~Point() {};

    Point(double M, double R, double X, double Y, Vector V) {
        m = M;
        r = R;
        x = X;
        y = Y;
        v = V;
        Vector A(0, 0);
        a = A;
    }
};

vector<Vector> counter_interactions(vector<Point> points) {
    int n = points.size();
    vector<vector<Vector>> interactions;
    interactions.resize(n);
    double constant = 0;
    vector<Vector> temp_F;
    Vector temp_r(0, 0);
    double dist_r = 0;


    for (int i = 0; i < n; ++i) {
        temp_F.resize(n);
        for (int j = i + 1; j < n; ++j) {
            constant = G * points[i].m;
            temp_r.setX(-(points[i].x + points[i].r - (points[j].x + points[j].r)));
            temp_r.setY(-(points[i].y + points[i].r - (points[j].y + points[j].r)));
            dist_r = sqrt(pow(temp_r.getX(), 2) + pow(temp_r.getY(), 2));
            constant /= pow(dist_r, 3);
            temp_F[j] = points[j].m * constant * temp_r;
        }
        interactions[i] = temp_F;
        temp_F.clear();
    }

    vector<Vector> result;
    Vector sum_F(0, 0);

    for (int i = 0; i < n; ++i) {
        sum_F.setX(0);
        sum_F.setY(0);
        for (int j = 0; j < n; ++j) {
            if (j < i) {
                interactions[i][j].setX(0 - interactions[j][i].getX());
                interactions[i][j].setY(0 - interactions[j][i].getY());
                sum_F = sum_F + interactions[i][j];
            } else if (j > i) {
                sum_F = sum_F + interactions[i][j];
            }
        }
        result.push_back(sum_F);
    }
    return result;
}

vector<Point> updater(vector<Point> points, vector<Vector> sum_F) {
    for (int i = 0; i < points.size(); ++i) {
        points[i].a = sum_F[i] / points[i].m;
        points[i].v = points[i].v + points[i].a * dt;
        points[i].x = points[i].x + points[i].v.getX() * dt;
        points[i].y = points[i].y + points[i].v.getY() * dt;
    }
    return points;
}


int main() {
    vector<Point> points;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double m, r, x, y;
        Vector v;
        cin >> m >> r >> x >> y >> v;
        Point p(m * pow(10, 9), r, x, y, v);
        points.push_back(p);
    }
    vector<Vector> sum_F;

    vector<sf::CircleShape> shapes;
    vector<sf::CircleShape> orbs;

    sf::RenderWindow window(sf::VideoMode(800, 800), "N-body problem");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i < N; ++i) {
            sum_F = counter_interactions(points);
            points = updater(points, sum_F);
            sum_F.clear();
        }

        for (int i = 0; i < n; ++i) {
            shapes.emplace_back(points[i].r, 30);
            shapes[i].setFillColor(sf::Color::Blue);
            shapes[i].move(points[i].x, points[i].y);
            if (orbs.size() < N_orbs) {
                orbs.emplace_back(0.5, 30);
                (*orbs.rbegin()).setFillColor(sf::Color::Blue);
                (*orbs.rbegin()).move(points[i].x + points[i].r, points[i].y + points[i].r);
            } else if (orbs.size() == N_orbs){
                orbs.erase(orbs.begin());
                orbs.emplace_back(0.5, 30);
                (*orbs.rbegin()).setFillColor(sf::Color::Blue);
                (*orbs.rbegin()).move(points[i].x + points[i].r, points[i].y + points[i].r);
            }
        }

        window.clear(sf::Color::White);


        for (int i = 0; i < n; ++i) {
            window.draw(shapes[i]);
        }
        for (int i = 0; i < orbs.size(); ++i) {
            window.draw(orbs[i]);
        }
        window.display();

        shapes.clear();


    }
    return 0;
}