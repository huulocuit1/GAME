#include "Colision.h"



Colision::Colision( EnemyManager*enemy, MarkManager*mark, Player*player)
{
	this->player = player;
	this->enemy = enemy;
	this->mark = mark;
	 
}
Colision::~Colision()
{
	delete player;
	delete enemy;
	delete mark;
}
void Colision::colwithButlet(Player*player, Butlet*butlet)
{
	if (Box::collide(player->getBox(), butlet->getBox()))
	{
		player->setAlive(false);
		player->killPlayer();		
		player->setReset(true);
	}
}
void Colision::checkCollison( float vpx, float vpy, Player*player)
{
	Quadtree* quadtree = createQuadTree( vpx, vpy);
	_ObjectList* return_object = new _ObjectList();
	if(currentstate==1)
	{ 

	quadtree->retrieve(return_object, player);
	
	for (auto x = return_object->begin(); x != return_object->end(); x++)
	{
		Objects*b = x._Ptr->_Myval;
		
		int colision = Box::collide(player->getBox(), b->getBox());
		if (b->getType() == NONEV)
		{
					
			int colision = Box::collide(player->getBox(), b->getBox());
			/*if (Box::Collide(player->getBox(), b->getBox()))
			{


				if (player->getBox().y - 7.8f >= b->getBox().y)
				{
					if (player->getstate() == JUMP||player->getstate()==FLIGHT)
						player->setstate(STAND);
					player->sety(b->getBox().y + player->getBox().getheight()/2+8);
					if (player->getvy() != 0)
					{
						player->setvy(0);

					}
				}

			}*/
			if (colision == 1)
			{


				player->setColLeft(true);

			}
			if (colision == 2)
			{
				player->setColRight(true);
			}
			if (player->getBox().y-player->getBox().getHeight()> b->getBox().y)
			{
				player->setColRight(false);
				player->setColLeft(false);
			}		

		}
		if (b->getType() == NONEH)
		{
			int colision = Box::collide(player->getBox(), b->getBox());
			if (Box::collide(player->getBox(), b->getBox()))
			{


				if (player->getBox().y - 7.8f >= b->getBox().y)
				{
					if (player->getState() == JUMP || player->getState() == FLIGHT)
						player->setState(STAND);
					player->setY(b->getBox().y + player->getBox().getHeight() / 2 + 8);
					if (player->getVy() != 0)
					{
						player->setVy(0);

					}
				}
			}			
			

		}
		if (b->getType() == _SPEC)
		{
			if (Box::collide(player->getBox(), b->getBox()))
			{
				if (player->getBox().y - 7.8f >= b->getBox().y)
				{
					if (player->getState() == JUMP || player->getState() == FLIGHT)
						player->setState(STAND);
					player->setY(b->getBox().y + player->getBox().getHeight() / 2 + 8);
					if (player->getVy() != 0)
					{
						player->setVy(0);

					}
				}
			}
		}
		if (b->getType() == MARK)
		{
			int colision = Box::collide(player->getBox(), b->getBox());
			Mark* mark = (Mark*)b;
			if (Box::collide(player->getBox(), b->getBox()) == 4)
			{

				
				if (mark->getHit() == 0)
				{
					mark->setColision(true);
				}
				else
				{
					mark->setColision(false);
					
				}
				if (mark->getStar() == true)
				{
				
					player->setReset(true);
					
				}
			/*	player->sety(mark->getBox().y - player->getBox().getheight()/2);*/

				if (player->getVy() != 0)
				{
					player->setVy(0);
				}
			}
			 else if( Box::collide(player->getBox(), mark->getBox())==5)
			{
				
				if (player->getBox().y - player->getBox().getHeight()/2 >= b->getBox().y)
				{
					if (player->getState() == JUMP || player->getState() == FLIGHT)
					{
						if (player->getSmallPlayer() == true)
						{
							player->setY(281);
						}
						else
						{
							player->setY(286);
						}
						
						player->setState(STAND);
						
				
					}
					player->setVy(0);
						
						
				}
			}
			 else
			 {
				 mark->setColision(false);
			 }
			 if (colision == 1)
			 {


				 player->setColLeft(true);

			 }
			 if (colision == 2)
			 {
				 player->setColRight(true);
			 }
			
			
			
			 
			 
				
				
			
			

		}
		if (b->getType() == COIN)
		{
			Coin*coin = (Coin*)b;
			if (Box::collide(player->getBox(), coin->getBox()))
			{
				coin->setCol(true);
			}
		}
		if (b->getType() == TURTLENORMAL)
		{
			TurtleNormal*turtle = (TurtleNormal*)b;
			
			int col = Box::collide(player->getBox(), b->getBox());
				if (turtle->getState() == DIE_)
				{
					
					if (Box::collide(player->getBox(), b->getBox()) == 1 || Box::collide(player->getBox(), b->getBox()) == 2)
					{
						if (player->getOmRua() == false)
						{
							player->setState(HIT_);
							if (turtle->getHit() == false)
							{

								turtle->setHit(true);
								turtle->setState(HIT);
							}
						}
						
						

					}
					
				}
				if (turtle->getState() == ALIVE)
				{
					if (Box::collide(player->getBox(), b->getBox()) == 1 || Box::collide(player->getBox(), b->getBox()) == 2)
					{
						if (player->getHitBrick() == true)
						{
							turtle->setState(DIE_);
						}
					}
					
				}
			
			
			
		}
		if (b->getType() == BRICK)
		{
			
			int colision = Box::collide(player->getBox(), b->getBox());
			Brick*brick = (Brick*)b;
			if (Box::collide(player->getBox(), b->getBox())==5)
			{
				if (player->getBox().y - 5 > b->getBox().y)
				{
					if (player->getState() == JUMP || player->getState() == FLIGHT)
						player->setState(STAND);
					player->setY(b->getBox().y + player->getBox().getHeight()/2 + b->getBox().getHeight());
					if (player->getVy() != 0)
					{
						player->setVy(0.0f);

					}
				}
				

			
			}
			if (colision == 1)
			{
				if (player->getHitBrick() == true)
				{
					brick->setCol(true);
				}
				else
				{
					player->setColLeft(true);
				}

				

			}
			if (colision == 2)
			{
				if (player->getHitBrick() == true)
				{
					brick->setCol(true);
				}
				else
				{
					player->setColRight(true);
				}
				
			}
			if (player->getBox().y - player->getBox().getHeight() > b->getBox().y)
			{
				player->setColRight(false);
				player->setColLeft(false);
			}
			
			
			
			if (colision == 4)
			{
				if (player->getCoDuoi() == true)
				{
					brick->setCol(true);
				}
				
			}
		
		}
		if (b->getType() == MUSHRUNNER)
		{
			MushRunner*mushrunner = (MushRunner*)b;
			if (mushrunner->getIsMush() == true)
			{
				if (mushrunner->getNumberColIsMush() == 0)
				{
					if (player->getSmallPlayer() == true)
					{
						if (Box::collide(player->getBox(), mushrunner->getBox()) == 4)
						{
							
							mushrunner->setNumberColIsMush(1);
						}
					}
				}
					
				else if (mushrunner->getNumberColIsMush() == 1)
				{
					if (Box::collide(player->getBox(), mushrunner->getBox()))
					{
						if (player->getSmallPlayer() == true)
						{
							player->setTran(true);
							mushrunner->setNumberColIsMush(2);
							
						}
					}
				}
				

			}
			else
			{
				if (Box::collide(player->getBox(), mushrunner->getBox()))
				{
					if (player->getSmallPlayer()==false)
					{
						mushrunner->setNumberColLeaf();
						mushrunner->setIsVisible(false);
						if (player->getCoDuoi() == false)
						{
							player->setTran(true);
						}
						
					}
					else
					{

						if (player->getSmallPlayer() == true&& mushrunner->getIsVisible() == true)
						{

							if (mushrunner->getNumberColIsLeaf() == 1)
							{
								mushrunner->setNumberColLeaf();
								player->setTran(true);
								mushrunner->setIsVisible(false);
							}
							
						}
					}
					

				}
			}
			
			

			
		}
		if (b->getType() == BUTTONP)
		{
			ButtonP*buttonp = (ButtonP*)b;
			
			int col = Box::collide(player->getBox(), buttonp->getBox());
				if (Box::collide(player->getBox(), buttonp->getBox())==5)
				{
					
				
					if (buttonp->getnumber_col() <= 1)
						{
							if (player->getHitBrick() == true)
							{
								buttonp->setcol(1);
							}
							
						}

					
					if (player->getBox().y - 7.5f >= b->getBox().y)
					{
						if (player->getState() == JUMP || player->getState() == FLIGHT)
							player->setState(STAND);
						if (player->getSmallPlayer() == true)
						{
							player->setY(b->getBox().y + player->getBox().getHeight() / 2 + 16);
						}
						else
						{
  							player->setY(b->getBox().y + player->getBox().getHeight() / 2 + 15);
						}

						if (player->getVy() != 0)
						{
							player->setVy(0);

						}
					}
					
	
				}
				if (col == 1)
				{
					
					player->setColLeft(true);
					

				}
				if (col == 2)
				{
					
					player->setColRight(true);
					
				}
				if (player->getBox().y - player->getBox().getHeight() > b->getBox().y)
				{					
					player->setColRight(false);
					player->setColLeft(false);
				}
				if (col == 3)
				{
					if (buttonp->getnumber_col() == 1)
					{
						buttonp->addnumber_col();
						player->setButtonP();
						player->setVy(0);
					}
				}

				
			
		}
		if (b->getType() == DOWN_H)
		{
			DownH*down_h = (DownH*)b;
			if (down_h->getType() == DOWN1)
			{
				if (Box::collide(player->getBox(), b->getBox()))
				{
					
					if (player->getBox().y - 7.8f >= b->getBox().y)
					{
						if (player->getState() == JUMP || player->getState() == FLIGHT)
							player->setState(STAND);
						player->setY(b->getBox().y + player->getBox().getHeight() / 2 + 8);
						if (player->getVy() != 0)
						{
							player->setVy(0);
							player->setColDown(true);

						}
					}

				}
				if (Box::collide(player->getBox(), b->getBox()) == 4)
				{
					player->setVy(0);
				}
			}
			else if (down_h->getType() == UP1)
			{
				if (Box::collide(player->getBox(), b->getBox())==4)
				{

					player->setDownUp(true);
					

				}
			}
			
		}
		if (b->getType() == FLOWER)
		{
			Flower*flower = (Flower*)b;
			
			if (flower->getVisible() == true)
			{
				if (Box::collide(player->getBox(), b->getBox()))
				{
					if (player->getSmallPlayer() == false) {
						player->setWithEnemy(true);
						player->setTran(true);

					}
					else
					{
						player->setAlive(false);
					}
				}
			}
			
		}
		if (b->getType() == MUSHROOM)
		{
			Mushroom*mush = (Mushroom*)b;
			int colision = Box::collide(player->getBox(), b->getBox());
			if (mush->getKind() == _JUMP)
			{
				if (colision == 3)
				{
					mush->setNotJump(true);
				}
				
				if (colision == 4)
				{
					if (player->getSmallPlayer() == false)
					{
						player->setWithEnemy(true);
						player->setTran(true);
					}
					else
					{
						player->setAlive(false);
					}
					
					player->setVy(0);
				}
				
			}
			if (mush->getKind() == NOT_JUMP)
			{
				if (colision == 3)
				{
					mush->setCol(true);
				}
			}
			
		}
		if (b->getType() == BUTTLET)
		{
			Butlet*butlet = (Butlet*)b;
			if (colision == 5)
			{
				


				if (player->getSmallPlayer()== false)
				{
					player->setWithEnemy(true);
					player->setTran(true);

				}
				else
				{
					player->setAlive(false);
					butlet->setVx(0);
					butlet->setVy(0);
				}
				



			}
		}

	}
	
	//Turtle colide width map
	for (int i = 0;i < turtlenomallist.size();i++)
	{
		
		
			if (turtlenomallist[i]->getCorlorTurtle() == RED||turtlenomallist[i]->getCorlorTurtle()==RED2)
			{
				return_object->clear();
				quadtree->retrieve(return_object, turtlenomallist[i]);
				for (auto x = return_object->begin();x != return_object->end();x++)
				{

					TurtleNormal*turtle = (TurtleNormal*)turtlenomallist[i];
					Objects*b = x._Ptr->_Myval;
					int colision = Box::collide(turtle->getBox(), b->getBox());
					if (b->getType()==NONEH)
					{
						int col = Box::collide(turtle->getBox(), b->getBox());
						if (col == 5)
						{

							if (turtle->getState() == DIE_)
							{
								turtle->setY(b->getBox().y + turtle->getBox().getHeight());
							}
							else if (turtle->getState() == HIT)
							{
								turtle->setY(b->getBox().y + turtle->getBox().getHeight() / 2 + 5);
								turtle->setVy(0);
							

							}
							else
							{
								turtle->setY(b->getBox().y + turtle->getBox().getHeight() - 4);
							}
						}
						
						
					}
					if (b->getType() == NONEV)
					{
						int colision = Box::collide(turtle->getBox(), b->getBox());
						if (colision ==5)
						{
						
							if (turtle->getBox().x <= b->getBox().x)
							{
								turtle->setColVRight(true);
							}
							else
							{
								
								turtle->setColVLeft(true);
							}
						}

					}
					if (b->getType() == MARK)
					{
						int colision = Box::collide(turtle->getBox(), b->getBox());
						Mark*mark = (Mark*)b;
						if (colision == 5)
						{
							
							
							if (turtle->getBox().x <= b->getBox().x)
							{
								turtle->setColMark(true);
								turtle->setColVRight(true);
								if (mark->getHit() == 0)
								{
									mark->setColision(true);
								}
								else
								{
									mark->setColision(false);
								}
								
							}
							else
							{
								turtle->setColVLeft(true);
							}
							
						}
					}
					
					if (b->getType() == MUSHRUNNER)
					{
						MushRunner*mushrunner = (MushRunner*)b;
						if (Box::collide(turtle->getBox(), b->getBox())==5)
							{
								mushrunner->setIsVisible(true);
								mushrunner->increaseNumberColIsLeaf();
							}
						
					}
					if (b->getType() == BRICK)
					{
						Brick*brick = (Brick*)b;
						if (turtle->getState() == HIT)
						{
							if (Box::collide(turtle->getBox(), b->getBox()))
							{
								turtle->setColMark(true);
								brick->setCol(true);
							}
						}
					}
					if (b->getType() == PLAYER)
					{
						if (turtle->getState() != DIE_)
						{


							if (colision == 5)
							{
								if (player->getBox().y - 8 > turtle->getBox().y)
								{
									turtle->setState(DIE_);
									turtle->setCol(true);
								}
								else
								{

									
									if (player->getSmallPlayer() == true)
									{
										player->setAlive(false);
									}
									else
									{
										player->setWithEnemy(true);
										player->setTran(true);

									}



								}

							}
						}
					}
					if (b->getType() == MUSHROOM)
					{
						Mushroom*mush = (Mushroom*)b;
						if (colision == 5)
						{
							if (turtle->getState() == HIT)
							{
								mush->setCol(true);
							}
						}
						
					}
					
					
					
				}
			}
			else
			{
				return_object->clear();
				quadtree->retrieve(return_object, turtlenomallist[i]);
			
				for (auto x = return_object->begin();x != return_object->end();x++)
				{
					
					TurtleNormal*turtle = (TurtleNormal*)turtlenomallist[i];
					Objects*b = x._Ptr->_Myval;
					int colision = Box::collide(turtle->getBox(), b->getBox());
					if (b->getType() == NONEH)
					{
						int col = Box::collide(turtle->getBox(), b->getBox());
						if (col == 5)
						{

							if (turtle->getState() == DIE_)
							{
								turtle->setY(b->getBox().y + turtle->getBox().getHeight());
							}
							else if (turtle->getState() == HIT)
							{

								turtle->setY(b->getBox().y + turtle->getBox().getHeight() / 2 + 5);


							}
							else
							{
								turtle->serColBotoom(true);
							}
						}


					}
					if (b->getType() == NONEV)
					{
						int colision = Box::collide(turtle->getBox(), b->getBox());
						if (colision == 5)
						{

							if (turtle->getBox().x <= b->getBox().x)
							{
								turtle->setColVRight(true);
							}
							else
							{

								turtle->setColVLeft(true);
							}
						}

					}
					if (b->getType() == MARK)
					{
						int colision = Box::collide(turtle->getBox(), b->getBox());
						Mark*mark = (Mark*)b;
						if (colision == 5)
						{


							if (turtle->getBox().x <= b->getBox().x)
							{
								turtle->setColMark(true);
								turtle->setColVRight(true);

								if (mark->getHit() == 0)
								{
									mark->setColision(true);
								}
								else
								{
									mark->setColision(false);
								}
							}
							else
							{
								turtle->setColVLeft(true);
							}
						}
					}

					if (b->getType() == MUSHRUNNER)
					{
						MushRunner*mushrunner = (MushRunner*)b;
						if (Box::collide(turtle->getBox(), b->getBox()) == 5)
						{
							mushrunner->setIsVisible(true);
							mushrunner->increaseNumberColIsLeaf();
						}

					}
					if (b->getType() == BRICK)
					{
						Brick*brick = (Brick*)b;
						if (turtle->getState() == HIT)
						{
							if (Box::collide(turtle->getBox(), b->getBox()))
							{
								turtle->setColMark(true);
								brick->setCol(true);
							}
						}
					}
					if (b->getType() == PLAYER)
					{
						if (turtle->getState() != DIE_)
						{


							if (colision == 5)
							{
								if (player->getBox().y - 8 > turtle->getBox().y)
								{
									turtle->setState(DIE_);
									turtle->setCol(true);
								}
								else
								{
									if (player->getSmallPlayer() == true)
									{
										player->setAlive(false);
									}
									else
									{
										player->setWithEnemy(true);
										player->setTran(true);

									}



								}

							}
						}
					}
					if (b->getType() == MUSHROOM)
					{
						Mushroom*mush = (Mushroom*)b;
						if (colision == 5)
						{
							if (turtle->getState() == HIT)
							{
								mush->setCol(true);
							}
						}

					}

				}
			}

	}

	//Mushroom colide with map
	for (int i = 0;i < mushroomlist.size();i++)
	{
		if (mushroomlist[i]->getKind() == _JUMP)
		{
			
			return_object->clear();
			quadtree->retrieve(return_object, mushroomlist[i]);
			for (auto x = return_object->begin(); x != return_object->end();x++)
			{
				Objects*b = x._Ptr->_Myval;
				Mushroom*mush = (Mushroom*)mushroomlist[i];
				int colision = Box::collide(mush->getBox(), b->getBox());
				if (b->getType() == NONEH)
				{
					if (Box::collide(mush->getBox(), b->getBox())==5)
					{
						mush->setBottom(true);
						mush->setColTop(false);
					}
				}
				if (b->getType() == MARK)
				{
					int col=Box::collide(mush->getBox(), b->getBox());
					if (col == 5)
					{
						if (mush->getBox().x <= b->getBox().x)
						{
							mush->setColVRight(true);
						}
						else
						{
							mush->setColVLeft(true);
						}


						if (mush->getY() < b->getBox().y)
						{
							mush->setColTop(true);
						}


					}
					
					
				}
				if (b->getType() == PLAYER)
				{
					if (colision == 5)
					{
						if (player->getBox().y < mush->getBox().y)
						{
							if (player->getSmallPlayer() == true)
							{
								player->setAlive(false);
							}
							else
							{
								player->setWithEnemy(true);
								player->setTran(true);

							}
						}
						else if (player->getBox().y - 16>mush->getBox().y)
						{
							mush->setNotJump(true);
						}
						else
						{
							if (player->getSmallPlayer() == true)
							{
								player->setAlive(false);
							}
							else
							{
								player->setWithEnemy(true);
								player->setTran(true);

							}

						}
					}
					
				}
							

				
			}
		}
		if (mushroomlist[i]->getKind() == NORMAL)
		{
			return_object->clear();
			quadtree->retrieve(return_object, mushroomlist[i]);
			for (auto x = return_object->begin(); x != return_object->end();x++)
			{

				Objects*b = x._Ptr->_Myval;
				Mushroom*mush = (Mushroom*)mushroomlist[i];
				int colision = Box::collide(mush->getBox(), b->getBox());
				
				if (b->getType() == NONEV||b->getType()==MARK)
				{
					if (colision == 5)
					{
						if (mush->getBox().x <=b->getBox().x)
						{
							mush->setColVRight(true);
						}
						else
						{
							mush->setColVLeft(true);
						}
					}
					
				}
				if (b->getType() == PLAYER)
				{
				
					if (colision ==5)
					{
						if (player->getBox().y-8 > mush->getBox().y)
						{
							mush->setCol(true);
						}
						else
						{
							if (player->getSmallPlayer() == true)
							{
								player->setAlive(false);
							}
							else
							{
								player->setWithEnemy(true);
								player->setTran(true);

							}
							
							
						
						}

					}
				}
				
				
			}
		}
		if (mushroomlist[i]->getKind() == NOT_JUMP)
		{
			return_object->clear();
			quadtree->retrieve(return_object, mushroomlist[i]);
			for (auto x = return_object->begin(); x != return_object->end();x++)
			{
				Objects*b = x._Ptr->_Myval;
				Mushroom*mush = (Mushroom*)mushroomlist[i];
				int colision = Box::collide(mush->getBox(), b->getBox());
				if (b->getType() == NONEH)
				{
					if (Box::collide(mush->getBox(), b->getBox()))
					{
						mush->setVy(0);
						mush->setY(268);
					}
				}
				if (b->getType() == MARK || b->getType() == NONEV)
				{
					if (colision == 5)
					{
						if (mush->getBox().x <= b->getBox().x)
						{
							mush->setColVRight(true);
						}
						else
						{
							mush->setColVLeft(true);
						}
					}
				}
				if (b->getType() == PLAYER)
				{
					if (colision == 5)
					{
						if (player->getBox().y - 8 > mush->getBox().y)
						{
							
						}
						
						else
						{
							if (player->getSmallPlayer() == true)
							{
								player->setAlive(false);
							}
							else
							{
								player->setWithEnemy(true);
								player->setTran(true);

							}



						}

					}
				}
			}

		}
	}
	//Mushrunner colide with map
	for (int i = 0;i < mushrunnerlist.size();i++)
	{

		if (mushrunnerlist[i]->getIsMush()==true)
		{
			return_object->clear();
			quadtree->retrieve(return_object, mushrunnerlist[i]);
			for (auto x = return_object->begin(); x != return_object->end();x++)
			{
				Objects*b = x._Ptr->_Myval;
				MushRunner*mushrunner = (MushRunner*)mushrunnerlist[i];
				if (b->getType() == NONEH)
				{
					
					
					if (Box::collide(mushrunner->getBox(), b->getBox())==5)
					{
						if (mushrunner->getBox().y>b->getBox().y)
						{
							float x = Box::collide(mushrunner->getBox(), b->getBox());
							mushrunner->setY(b->getBox().y + b->getBox().getHeight() / 2 + 10);
						}
						


					}
					

				}
				if (b->getType() == NONEV)
				{
					int colision = Box::collide(mushrunner->getBox(), b->getBox());
					if (colision == 5)
					{
						mushrunner->setVx(-1);
					}
				}
				

				
			}
		
		}
		else
		{
			return_object->clear();
			quadtree->retrieve(return_object, mushrunnerlist[i]);
			for (auto x = return_object->begin(); x != return_object->end();x++)
			{
				Objects*b = x._Ptr->_Myval;
				MushRunner*mushrunner = (MushRunner*)mushrunnerlist[i];
				if (b->getType() == TURTLENORMAL)
				{
					
					if (Box::collide(b->getBox(), mushrunner->getBox()) == 5)
					{
						mushrunner->setIsVisible(true);
						mushrunner->increaseNumberColIsLeaf();
					}
				}
			}
			
		}
		
	}
	}
 if (currentstate == 2)
	{
		return_object->clear();
		quadtree->retrieve(return_object, player);
		for (auto x = return_object->begin(); x != return_object->end(); x++)
		{
			Objects*b = x._Ptr->_Myval;

			int colision = Box::collide(player->getBox(), b->getBox());
			if (b->getType() == NONEV)
			{

				int colision = Box::collide(player->getBox(), b->getBox());
				
				if (colision == 1)
				{


					player->setColLeft(true);
					

				}
				if (colision == 2)
				{
					
					player->setColRight(true);
					
				}
				
				if (player->getBox().y - player->getBox().getHeight() > b->getBox().y)
				{
					player->setColRight(false);
					player->setColLeft(false);
				}






			}
			if (b->getType() == NONEH)
			{
				int colision = Box::collide(player->getBox(), b->getBox());
				if (Box::collide(player->getBox(), b->getBox()))
				{


					if (player->getBox().y - 7.8f >= b->getBox().y)
					{
						if (player->getState() == JUMP || player->getState() == FLIGHT)
							player->setState(STAND);
						player->setY(b->getBox().y + player->getBox().getHeight() / 2 + 8);
						if (player->getVy() != 0)
						{
							player->setVy(0);

						}
					}
				}






			}
	
			if (b->getType() == MARK)
			{
				int colision = Box::collide(player->getBox(), b->getBox());
				Mark* mark = (Mark*)b;
				if (Box::collide(player->getBox(), b->getBox()) == 4)
				{

					if (mark->getHit() == 0)
					{
						mark->setColision(true);
					}
					else
					{
						mark->setColision(false);
					}
					player->setY(mark->getBox().y - player->getBox().getHeight() / 2);

					if (player->getVy() != 0)
					{
						player->setVy(0);
					}
				}
				else if (Box::collide(player->getBox(), mark->getBox()) == 5)
				{

					if (player->getBox().y - player->getBox().getHeight() / 2 >= b->getBox().y)
					{
						if (player->getState() == JUMP || player->getState() == FLIGHT)
						{
							if (player->getSmallPlayer() == true)
							{
								player->setY(281);
							}
							else
							{
								player->setY(286);
							}

							player->setState(STAND);


						}
						player->setVy(0);


					}
				}
				else
				{
					mark->setColision(false);
				}
				if (colision == 1)
				{


					player->setColLeft(true);

				}
				if (colision == 2)
				{
					player->setColRight(true);
				}










			}
			if (b->getType() == COIN)
			{
				Coin*coin = (Coin*)b;
				if (Box::collide(player->getBox(), coin->getBox()))
				{
					coin->setCol(true);
				}
			}
			
			if (b->getType() == BRICK)
			{

				int colision = Box::collide(player->getBox(), b->getBox());
				Brick*brick = (Brick*)b;
				if (Box::collide(player->getBox(), b->getBox()) == 5)
				{
					if (player->getBox().y - 5 > b->getBox().y)
					{
						if (player->getState() == JUMP || player->getState() == FLIGHT)
							player->setState(STAND);
						player->setY(b->getBox().y + player->getBox().getHeight() / 2 + b->getBox().getHeight());
						if (player->getVy() != 0)
						{
							player->setVy(0.0f);

						}
					}


				}
				if (colision == 1)
				{
					if (player->getHitBrick() == true)
					{
						brick->setCol(true);
					}
					else
					{
						player->setColLeft(true);
					}



				}
				if (colision == 2)
				{
					if (player->getHitBrick() == true)
					{
						brick->setCol(true);
					}
					else
					{
						player->setColRight(true);
					}

				}
				if (player->getBox().y - player->getBox().getHeight() > b->getBox().y)
				{
					player->setColRight(false);
					player->setColLeft(false);
				}



				if (colision == 4)
				{
					if (player->getCoDuoi() == true)
					{
						brick->setCol(true);
					}
					else
					{
						player->setVy(0);
					}
				}

			}
		
			
		
			if (b->getType() == FLOWER)
			{
				Flower*flower = (Flower*)b;

				if (flower->getVisible() == true)
				{
					if (Box::collide(player->getBox(), b->getBox()))
					{
						if (player->getSmallPlayer() == false) {
							player->setWithEnemy(true);
							player->setTran(true);

						}
						else
						{
							player->setAlive(false);
						}
					}
				}

			}
			if (b->getType() == MUSHROOM)
			{
				Mushroom*mush = (Mushroom*)b;
				int colision = Box::collide(player->getBox(), b->getBox());
				if (mush->getKind() == _JUMP)
				{
					if (colision == 3)
					{
						mush->setNotJump(true);
					}

					if (colision == 4)
					{
						if (player->getSmallPlayer() == false)
						{
							player->setWithEnemy(true);
							player->setTran(true);
						}
						else
						{
							player->setAlive(false);
						}

						player->setVy(0);
					}

				}
				if (mush->getKind() == NOT_JUMP)
				{
					if (colision == 3)
					{
						mush->setCol(true);
					}
				}

				if (player->getCoDuoi() == true)
				{
					if (colision == 5)
					{
						mush->setCol(true);
					}
				}

			}
			if (b->getType() == BUTTLET)
			{
				Butlet*butlet = (Butlet*)b;
				if (colision == 5)
				{



					if (player->getSmallPlayer() == false)
					{
						player->setWithEnemy(true);
						player->setTran(true);

					}
					else
					{
						player->setAlive(false);
						butlet->setVx(0);
						butlet->setVy(0);
					}




				}
			}

		}
		for (int i = 0;i < mushroomlist.size();i++)
		{
			if (mushroomlist[i]->getKind() == _JUMP)
			{

				return_object->clear();
				quadtree->retrieve(return_object, mushroomlist[i]);
				for (auto x = return_object->begin(); x != return_object->end();x++)
				{
					Objects*b = x._Ptr->_Myval;
					Mushroom*mush = (Mushroom*)mushroomlist[i];
					int colision = Box::collide(mush->getBox(), b->getBox());
					if (b->getType() == NONEH)
					{
						if (Box::collide(mush->getBox(), b->getBox()) == 5)
						{
							mush->setBottom(true);
							mush->setColTop(false);
						}
					}
					if (b->getType() == MARK||b->getType()==BRICK)
					{
						int col = Box::collide(mush->getBox(), b->getBox());
						if (col == 5)
						{
							if (mush->getBox().x <= b->getBox().x)
							{
								mush->setColVRight(true);
							}
							else
							{
								mush->setColVLeft(true);
							}


							if (mush->getY() < b->getBox().y)
							{
								mush->setColTop(true);
							}


						}


					}
					if (b->getType() == PLAYER)
					{
						if (colision == 5)
						{
							if (player->getBox().y < mush->getBox().y)
							{
								if (player->getSmallPlayer() == true)
								{
									player->setAlive(false);
								}
								else
								{
									player->setWithEnemy(true);
									player->setTran(true);

								}
							}
							else if (player->getBox().y - 16>mush->getBox().y)
							{
								mush->setNotJump(true);
							}
							else
							{
								if (player->getSmallPlayer() == true)
								{
									player->setAlive(false);
								}
								else
								{
									player->setWithEnemy(true);
									player->setTran(true);

								}

							}
						}

					}



				}
			}
			if (mushroomlist[i]->getKind() == NORMAL)
			{
				return_object->clear();
				quadtree->retrieve(return_object, mushroomlist[i]);
				for (auto x = return_object->begin(); x != return_object->end();x++)
				{

					Objects*b = x._Ptr->_Myval;
					Mushroom*mush = (Mushroom*)mushroomlist[i];
					int colision = Box::collide(mush->getBox(), b->getBox());

					if (b->getType() == NONEV || b->getType() == MARK|| b->getType() == BRICK)
					{
						if (colision == 5)
						{
							if (mush->getBox().x <= b->getBox().x)
							{
								mush->setColVRight(true);
							}
							else
							{
								mush->setColVLeft(true);
							}
						}

					}
					if (b->getType() == PLAYER)
					{

						if (colision == 5)
						{
							if (player->getBox().y - 8 > mush->getBox().y)
							{
								mush->setCol(true);
							}
							else
							{
								if (player->getSmallPlayer() == true)
								{
									player->setAlive(false);
								}
								else
								{
									player->setWithEnemy(true);
									player->setTran(true);

								}



							}

						}
					}


				}
			}
			if (mushroomlist[i]->getKind() == NOT_JUMP)
			{
				return_object->clear();
				quadtree->retrieve(return_object, mushroomlist[i]);
				for (auto x = return_object->begin(); x != return_object->end();x++)
				{
					Objects*b = x._Ptr->_Myval;
					Mushroom*mush = (Mushroom*)mushroomlist[i];
					int colision = Box::collide(mush->getBox(), b->getBox());
					if (b->getType() == NONEH)
					{
						if (Box::collide(mush->getBox(), b->getBox()))
						{
							mush->setVy(0);
							mush->setY(268);
						}
					}
					if (b->getType() == MARK || b->getType() == NONEV)
					{
						if (colision == 5)
						{
							if (mush->getBox().x <= b->getBox().x)
							{
								mush->setColVRight(true);
							}
							else
							{
								mush->setColVLeft(true);
							}
						}
					}
					if (b->getType() == PLAYER)
					{
						if (colision == 5)
						{
							if (player->getBox().y - 8 > mush->getBox().y)
							{

							}

							else
							{
								if (player->getSmallPlayer() == true)
								{
									player->setAlive(false);
								}
								else
								{
									player->setWithEnemy(true);
									player->setTran(true);

								}



							}

						}
					}
				}

			}
		}
	}






	quadtree->clear();
	delete return_object;
	delete quadtree;


}
Quadtree* Colision::createQuadTree(float vpx, float vpy)
{
	
	if (currentstate == 1)
	{		
		Quadtree* quadtree = new Quadtree(1, new Box(vpx - 80, vpy - 240, BUFFER_WIDTH + 200, 240));
		mushroomlist = enemy->getMushList();
		this->boxlist_col_V = Background::getInstane()->getBoxListColV();
		this->boxlist_col_H = Background::getInstane()->getBoxListColH();
		this->marklist = mark->getmarklist();
		this->coinlist = mark->getcoinlist();
		this->turtlenomallist = enemy->getTurtleNormalList();
		this->bricklist = mark->getbricklist();
		this->mushrunnerlist = mark->getmushrunnerlist();
		this->buttonlist = mark->getbuttonList();
		this->speclis = Background::getInstane()->getSpectList();
		this->down_list = Background::getInstane()->getDownList();
		this->flowerlist = enemy->getFlowerList();
		this->butlet = enemy->getButlet();
		quadtree->insert(player);
		for (int i = 0; i < mushroomlist.size(); i++)
		{
			if (mushroomlist[i]->getVisible() == true)
			{
				quadtree->insert(mushroomlist[i]);
			}


		}
		for (int i = 0; i < speclis.size(); i++)
		{
			quadtree->insert(speclis[i]);
		}
		for (int i = 0;i < boxlist_col_V.size();i++)
		{

			quadtree->insertV(&boxlist_col_V[i]);
		}
		for (int i = 0;i < boxlist_col_H.size();i++)
		{
			quadtree->insertH(&boxlist_col_H[i]);


		}
		for (int i = 0;i < marklist.size();i++)
		{
			if (marklist[i]->getVisible() == true)
			{
				quadtree->insert(marklist[i]);
			}

		}
		for (int i = 0;i < coinlist.size();i++)
		{
			quadtree->insert(coinlist[i]);
		}
		for (int i = 0;i < turtlenomallist.size();i++)
		{
			if (turtlenomallist[i]->getVisible() == true)
			{
				quadtree->insert(turtlenomallist[i]);
			}


		}
		for (int i = 0;i < bricklist.size();i++)
		{
			quadtree->insert(bricklist[i]);
		}
		for (int i = 0;i < mushrunnerlist.size();i++)
		{
			quadtree->insert(mushrunnerlist[i]);
		}
		for (int i = 0;i < buttonlist.size();i++)
		{
			quadtree->insert(buttonlist[i]);
		}
		for (int i = 0;i < down_list.size();i++)
		{
			quadtree->insert(down_list[i]);
		}
		for (int i = 0;i < flowerlist.size();i++)
		{
			quadtree->insert(flowerlist[i]);
		}
		quadtree->insert(butlet);
		return quadtree;
	}
	else if (currentstate == 2)
	{



		Quadtree* quadtree = new Quadtree(1, new Box(vpx - 80, vpy - 240, BUFFER_WIDTH + 100, 240));
		float min = vpx;
		float max = vpx + BUFFER_WIDTH;
		mushroomlist = enemy->getMushList();
		this->boxlist_col_V = Background::getInstane()->getBoxListColV();
		this->boxlist_col_H = Background::getInstane()->getBoxListColH();
		this->flowerlist = enemy->getFlowerList();
		this->coinlist = mark->getcoinlist();
		this->marklist = mark->getmarklist();
		this->bricklist = mark->getbricklist();
		this->butlet = enemy->getButlet();
		quadtree->insert(butlet);
		quadtree->insert(player);
		for (int i = 0; i < mushroomlist.size(); i++)
		{
			if (mushroomlist[i]->getVisible() == true)
			{
				quadtree->insert(mushroomlist[i]);
			}


		}
		for (int i = 0;i < boxlist_col_V.size();i++)
		{
			if (boxlist_col_V[i].x > min&&boxlist_col_V[i].x < max)
			{
				quadtree->insertV(&boxlist_col_V[i]);
			}
			

		}
		for (int i = 0;i < boxlist_col_H.size();i++)
		{

			quadtree->insertH(&boxlist_col_H[i]);


		}
		for (int i = 0;i < coinlist.size();i++)
		{
			quadtree->insert(coinlist[i]);
		}
		for (int i = 0;i < flowerlist.size();i++)
		{
			quadtree->insert(flowerlist[i]);
		}
		for (int i = 0;i < marklist.size();i++)
		{
			if (marklist[i]->getVisible() == true)
			{
				quadtree->insert(marklist[i]);
			}

		}
		for (int i = 0;i < bricklist.size();i++)
		{
			quadtree->insert(bricklist[i]);
		}
		return quadtree;
	}
	

}

