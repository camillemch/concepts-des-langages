//
//  expression.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "Expression.hpp"

int Expression::nb_instances_rest = 0;
int Expression::nb_instances_tot = 0;

int Expression::nb_instances_restant(){
    return nb_instances_rest;
}

int Expression::nb_instances_total(){
    return nb_instances_tot;
}
