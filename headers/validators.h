unsigned short skillCostsValidator (Character *C, Skill *skill) {

  // If this return 1 you can attack  
  return (C->aP > skill->actionCost && C->eP > skill->energyCost);
}