#include "Player.h"

extern int currentstate=1;
extern int playerlife=0;
extern int score=0;
extern int changelevel = 0;

Player::Player()
{
}


Player::~Player()
{
	delete(player_small_tand_right);
	delete(player_small_tand_left);
}
Player::Player(LPDIRECT3DDEVICE9 d3ddv, float X, float Y)
{
	
	x = X;
	y = Y;	
	vx = 0;
	vy = 0;
	initPlayer(d3ddv);

	type = PLAYER;
	
	
}
void Player::initPlayer(LPDIRECT3DDEVICE9 d3ddv)
{
	test = new Sprite(d3ddv, L"Images\\Map\\Background\\2.jpg",16, 16, 1, 1);
	smallPlayer = true;
	coduoi = false;
	number_live = 0;
	time_reset = 0;
	player_state = STAND;
	stand_right = true;
	before_x_col = x;
	player_alive = true;
	starty = y;
	startx = x;
	last_time = 0;

	///PLAYER_SMALL
	this->player_small_tand_left = new Sprite(d3ddv, L"Images\\Player\\stand_left.png", 12, 15, 2, 2);
	this->player_small_tand_right = new Sprite(d3ddv, L"Images\\Player\\stand_right.png", 12, 15, 1, 1);
	this->player_small_jump_left = new Sprite(d3ddv, L"Images\\Player\\jump_left.png", 16, 16, 2, 2);
	this->player_small_jump_right = new Sprite(d3ddv, L"Images\\Player\\jump_right.png", 16, 16, 2, 2);
	this->player_small_run_left = new Sprite(d3ddv, L"Images\\Player\\go_left.png", 16, 16, 3, 3);
	this->player_small_run_right = new Sprite(d3ddv, L"Images\\Player\\go_right.png", 16, 16, 3, 3);
	this->player_small_die = new Sprite(d3ddv, L"Images\\Player\\die_.png", 16, 16, 1, 1);
	this->player_small_hit_turtle = new Sprite(d3ddv, L"Images\\Player\\normal_hit.png", 16, 16, 2, 2);
	this->player_small_acc = new Sprite(d3ddv, L"Images\\Player\\giatoc.png", 14, 16, 2, 2);
	this->player_tran_right=new Sprite(d3ddv, L"Images\\Player\\tran.png", 14, 27, 4, 4);
	this->player_tran_left = new Sprite(d3ddv, L"Images\\Player\\tran_left.png", 14, 27, 4, 4);

	///RED
	this->player_small_omrua_red_stand = new Sprite(d3ddv, L"Images\\Player\\Omrua\\small\\omrua_red_stand.png", 25, 17, 2, 2);
	this->player_small_omrua_red_run_left= new Sprite(d3ddv, L"Images\\Player\\Omrua\\small\\omrua_red_run_left.png", 26, 17, 2, 2);
	this->player_small_omrua_red_run_right= new Sprite(d3ddv, L"Images\\Player\\Omrua\\small\\omrua_red_run_right.png", 26, 17, 2, 2);
	///GREEN
	this->player_small_omrua_green_stand = new Sprite(d3ddv, L"Images\\Player\\Omrua\\small\\omrua_green_small_stand.png", 25, 17, 2, 2);
	this->player_small_omrua_green_run_left = new Sprite(d3ddv, L"Images\\Player\\Omrua\\small\\omrua_left_small_right.png", 26, 17, 2, 2);
	this->player_small_omrua_green_run_right = new Sprite(d3ddv, L"Images\\Player\\Omrua\\small\\omrua_green_small_right.png", 26, 17, 2, 2);
	
	

	///PLAYER_SUPPER
	this->player_supper_tand_right = new Sprite(d3ddv, L"Images\\Player\\stand_right_s.png", 14, 27, 1, 1);
	this->player_supper_run_right=new Sprite(d3ddv, L"Images\\Player\\go_right_s.png", 16, 27, 4, 4);
	this->player_supper_run_left=new Sprite(d3ddv, L"Images\\Player\\go_left_s.png", 16, 27, 4, 4);
	this->player_supper_tand_left=new Sprite(d3ddv, L"Images\\Player\\stand_left_s.png", 16, 27, 1, 1);
	this->player_supper_jump_right = new Sprite(d3ddv, L"Images\\Player\\jump_right_s.png", 16, 26, 1, 1);
	this->player_supper_jump_left = new Sprite(d3ddv, L"Images\\Player\\jump_left_s.png", 16, 26, 1, 1);
	this->player_supper_coduoi_hit_turtle= new Sprite(d3ddv, L"Images\\Player\\hit.png", 22, 28, 4, 4);
	this->player_super_tran = new Sprite(d3ddv, L"Images\\Player\\super_tran.png", 16, 16, 1, 1);
	///RED
	this->player_supper_omrua_red_run_left = new Sprite(d3ddv,L"Images\\Player\\Omrua\\Super\\omrua_left_S.png", 27, 27, 2, 2);
	this->player_supper_omrua_red_run_right= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Super\\omrua_right_S.png", 27, 27, 2, 2);
	this->player_supper_omrua_red_stand_left= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Super\\omrua_stand_left_S.png", 25, 27, 1, 1);
	this->player_supper_omrua_red_stand_right = new Sprite(d3ddv, L"Images\\Player\\Omrua\\Super\\omrua_stand_right_S.png", 25, 27, 1, 1);
	///GREEN
	this->player_supper_omrua_green_run_left= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Super\\omrua_green_left_S.png", 27, 27, 2, 2);
	this->player_supper_omrua_green_run_right= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Super\\omrua_green_right_S.png", 27, 27, 2, 2);
	this->player_supper_omrua_green_stand= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Super\\super_green_stand_omrua.png", 25, 27, 2, 2);




	///PLAYER_CODUOI
	this->player_coduoi_stand_right = new Sprite(d3ddv, L"Images\\Player\\duoi_stand_right.png", 21, 28, 1, 1);
	this->player_coduoi_run_right = new Sprite(d3ddv, L"Images\\Player\\duoi_run_right.png", 23, 28, 3, 3);
	this->player_coduoi_run_left = new Sprite(d3ddv, L"Images\\Player\\duoi_run_left.png", 23, 28, 3, 3);
	this->player_coduoi_stand_left = new Sprite(d3ddv, L"Images\\Player\\duoi_stand_left.png", 21, 28, 1, 1);
	this->player_coduoi_jump_right = new Sprite(d3ddv, L"Images\\Player\\coduoi_jump_right.png", 23, 27, 1, 1);
	this->player_coduoi_jump_left = new Sprite(d3ddv, L"Images\\Player\\coduoi_jump_left.png", 23, 27, 1, 1);
	this->player_coduoi_flight_right = new Sprite(d3ddv, L"Images\\Player\\flight_right.png", 24, 28, 3, 3);
	this->player_coduoi_flight_left= new Sprite(d3ddv, L"Images\\Player\\flight_left.png", 24, 28, 3, 3);
	this->player_coduoi_acc = new Sprite(d3ddv, L"Images\\Player\\giatoc_S.png", 16, 30, 4, 4);
	this->player_coduoi_xyz = new Sprite(d3ddv, L"Images\\Player\\xyz.png", 23, 28, 3, 3);
	///RED
		this->player_coduoi_omrua_red_stand= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Coduoi\\coduoi_red_omrua_stand.png", 32, 28, 2, 2);
		this->player_coduoi_omrua_red_run_left= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Coduoi\\coduoi_red_omrua_run_left.png", 33, 28, 2, 2);
		this->player_coduoi_omrua_red_run_right= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Coduoi\\coduoi_red_omrua_run_right.png", 33, 28, 2, 2);

		///GREEN	
		this->player_coduoi_omrua_green_stand= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Coduoi\\coduoi_stand_omrua.png", 32, 28, 2, 2);
		this->player_coduoi_omrua_green_run_left= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Coduoi\\coduoi_green_omrua_run_left.png", 33, 28, 2, 2);
		this->player_coduoi_omrua_green_run_right= new Sprite(d3ddv, L"Images\\Player\\Omrua\\Coduoi\\coduoi_green_omrua_run_right.png", 33, 28, 2, 2);


	this->is_col_with_flower = false;
	this->reset_player = false;
	_time = 0;
	_time2 = 0;
	time_tranform = 0;
	time_hit = 0;





}
void Player::updateViewPort(float*vpx,float *vpy,float time)
{
	
	if (x - BUFFER_WIDTH / 2 > 0&&x+BUFFER_WIDTH/2<MAX_MAP1-box.getWidth())
	{
		*vpx = this->x - BUFFER_WIDTH / 2;
		before_vp = *vpx;
	}
	
	
	
	 else if (x + BUFFER_WIDTH / 2>MAX_MAP1 - box.getWidth())
	{
		*vpx = before_vp;
	}
	 else
	 {
		 *vpx = 0;
	 }
	 


	if (y >=400)
	{
		*vpy = this->y + BUFFER_HEIGHT/2;
	
	}
	else if (y <224)
	{
		if (player_alive)
		{
			*vpy = BUFFER_HEIGHT - 24;
		}
		 
	}
	else
	{
		*vpy = MAP1_TILE_SIZE_HEIGHT - BUFFER_HEIGHT;
		
	}
	if (!player_alive)
	{
		if (time_reset > 3000)
		{
			*vpx= 0;
			
		}
		else
		{
			time_reset += time;
		}

		
		
	}

	
}
void Player::updatePlayer(FKeyboard*kbd, float vpx, float vpy,double time)
{
	
	if (player_alive)
	{
#pragma region Init_Key
		bool leftPress = kbd->isKeyDown(DIK_LEFT);
		bool rightPress = kbd->isKeyDown(DIK_RIGHT);
		bool spacePress = kbd->isKeyDown(DIK_SPACE);
		bool APress = kbd->isKeyDown(DIK_S);
		bool CPress = kbd->isKeyDown(DIK_C);
		bool DPress = kbd->isKeyDown(DIK_D);
		bool FPress = kbd->isKeyDown(DIK_F);
		bool KPress = kbd->isKeyDown(DIK_K);
		bool MPress = kbd->isKeyDown(DIK_M);
		bool BPress = kbd->isKeyDown(DIK_B);
		bool TPress = kbd->isKeyDown(DIK_T);
		bool HPress = kbd->isKeyDown(DIK_H);
		bool XPress = kbd->isKeyDown(DIK_X);

#pragma endregion

#pragma region  Player_State
		if (y > 24)
		{
			
				vy -= 0.16;
		
			
		}
		else
		{
			vy = 0;
		}
		if (x >= MAX_MAP1- box.getWidth()-16)
		{
			
			if (leftPress)
			{
				vx = -WALK_SPEED;
				stand_right = false;
				
				
			}
			else
			{
				vx = 0;
			}
		}

		if (player_state == JUMP)
		{
			if (rightPress)
			{
				stand_right = true;
				if (col_right)
				{
					vx = 0.2f;
				}
				else
				{
					vx = 0.9f;
				}
				
				


			}
			if (leftPress)
			{
				stand_right = false;
				if (col_left)
				{
					vx = -0.2f;
				}
				else
				{
					vx = -0.6f;
				}

			}
			if (!col_left&&!col_right)
			{
				before_col_v = x;
			}
			if (!col_bootom)
			{
				before_col_h = y;
			}
			

			
			

		}
		if (player_state == STAND)
		{
			
			if (CPress)
			{
				if (smallPlayer == false)
				{
					if (coduoi)
					{
						player_state = FLIGHT;
					}

				}

			}
			else if (spacePress)
			{
				player_state = JUMP;
				if (smallPlayer == true)
				{
					if (jumped == false)
					{
						vy = 4.4f;
						jumped = true;
					}
					
				}
				else if (jumped == false)
				{
					jumped = true;
					vy = 4.6f;
				}
				if (rightPress&&spacePress||leftPress&&spacePress)
				{
					vx = 0;
				}
				
				

			}
			else
			{
				
				vx = 0;
			
				
				
			
			}

			
			


		}
		if (player_state == RUN)
		{
			if (CPress)
			{
				if (smallPlayer == false)
				{
					player_state = FLIGHT;
				}
			}

			if (vx > 0)
			{
				if (leftPress)
				{
					if (!om_rua)
					{
						player_state = ACCELERATION;
					}
					else
					{
						stand_right = false;
						vx = -WALK_SPEED;
					}

				}

			}
			else if(vx<0)
			{
				if (rightPress)
				{
					if (!om_rua)
					{
						player_state = ACCELERATION;
					}
					else
					{
						stand_right = true;
						vx = WALK_SPEED;
					}
				}
			}
			if (rightPress&&spacePress)
			{
				vx = 1.0f;
				vy = 4.4f;
			}
			else if (leftPress&&spacePress)
			{
				vx = -1.0f;
				vy = 4.4f;
			}

			if (!col_left&&!col_right)
			{
				before_col_v = x;
			}
			
			
			
			


		}
		if (player_state == FLIGHT)
		{

			vy = 0;
			if (y < 672 - 100)
			{
				y += 1;
			}
			else
			{
				y -= 1;
			}


			if (rightPress)
			{
				stand_right = true;
				vx = 2;
			}
			else if (leftPress)
			{
				vx = -2;
				stand_right = false;
			}
			else if (!rightPress&&!leftPress)
			{
				vx = 0;
			}
			if (!CPress)
			{
				y--;
			}
			
			if (!col_left&&!col_right)
			{
				before_col_v = x;
			}


		}
		if (player_state == HIT_)
		{
			vx = 0;
			if (time_hit > 800)
			{
				player_state = STAND;
				time_hit = 0;
			}
			else
			{
				time_hit += time;
			}
		}
		if (player_state == ACCELERATION)
		{
			if (_time > 300)
			{
				player_state = STAND;
				if (stand_right == true)
				{
					stand_right = false;
				}
				else
				{
					stand_right = true;
				}
				_time = 0;
			}
			else
			{

				vy = 0;
				_time += time;
			}
		}
		if (player_state == TRAN)
		{
			if (!col_with_enemy)
			{
				if (_time > 300)
				{
					if (smallPlayer == true)
					{
						smallPlayer = false;
					}
					else if (smallPlayer == false)
					{
						coduoi = true;
					}

					player_state = JUMP;
					y = before_y_tran + 16;
					_time = 0;
				}
				else
				{
					_time += time;
					vy = 0;
					vx = 0;

				}
			}
			else
			{
				if (_time > 300)
				{
					
					if (smallPlayer == false)
					{
						if (coduoi)
						{
							coduoi = false;
							player_state = JUMP;
						}
						else
						{
							smallPlayer = true;
							player_state = JUMP;
						}
					}
					else
					{
						
					}
									
					y = before_y_tran + 16;
					col_with_enemy = false;
					_time = 0;
				}
				else
				{
					_time += time;
					vy = 0;
					vx = 0;

				}
			}
		}
		if (down_h)
		{
			if (_time > 2000)
			{
				x = 10;
				y = 128;
				player_state = JUMP;
				_time = 0;
				down_h = false;
			}
			else
			{
				
				_time += time;
			}
		}
		if (dow_up)
		{
			if (_time > 1000)
			{
				y = starty+30;
				_time = 0;
				dow_up = false;
				
				player_state = JUMP;
			}
			else
			{
				vy = 0.5;
				_time += time;
			}
		}
		if (col_left&&hit_brick == false)
		{
			
			if (rightPress)
			{
								
				col_left = false;
			}
			else
			{
				vx = 0;
				x = before_col_v;
			}
			
			
			


		}
		if (col_right&&hit_brick == false)
		{
		
			
			if (leftPress)
			{
				col_right = false;
			}
			else
			{
				vx = 0;
				x = before_col_v-1;
			}
		}
		
		
		
#pragma endregion


#pragma region Litmit_Player
		if (x < vpx) x = vpx;
		if (currentstate == 1)
		{
			if (x < MIN_MAP1) x = MIN_MAP1;
			if (x > MAX_MAP1) x = MAX_MAP1;
		}
#pragma endregion 		
#pragma region Control_keyboard
		
		
		if (rightPress&&!leftPress)
		{
			
			if (player_state==STAND)
			{
				
				player_state = RUN;
				this->stand_right = true;
				vx = WALK_SPEED;
				

			}
			else if (player_state == RUN)
			{
				if (spacePress)
				{
					if (jumped == false)
					{
						player_state = JUMP;
						jumped = true;
					}
					

				}
				
			

			}
			






		}

		//Go left
		else if (leftPress&&!rightPress)
		{
			if (player_state == STAND)
			{
				player_state = RUN;
				this->stand_right = false;
				vx = -WALK_SPEED;

				
			}
			else if (player_state == RUN)
			{
				if (spacePress)
				{
					if (jumped == false)
					{
						player_state = JUMP;
						jumped = true;
					}
					


				}
			}




		}
		else if (!rightPress&&!leftPress)
		{
			
			if (player_state == RUN)
			{
				if (_time >100)
				{
					player_state = STAND;
					vx = 0;
					
					_time = 0;
					
				}
				else
				{
										
					_time += time;
				}
				

			}
			
		}
		if (vy <-0.5)
		{
			player_state = JUMP;
		}

		if (!CPress)
		{
			if (player_state == FLIGHT)
			{
				vy--;
			}
		}
		if (!spacePress)
		{
			jumped = false;
			/*if (player_state == JUMP)
			{
				vy -= 0.1f;


			}*/
		}
		
		if (tran_)
		{
			if (_time > 100)
			{
				tran_ = false;
				_time = 0;
			}
			else
			{
				player_state = TRAN;
				_time += time;
				before_y_tran = y;
				vy = 0;
			}
			
		}
		if (DPress)
		{
			player_state = TRAN;
			_time += time;
			before_y_tran = y;
			vy = 0;

			//y += vy;//Neu dang bay ma nhan Phim D->Mario bay thap xuong

		}
		if (FPress)
		{

			coduoi = false;
			player_state = STAND;


		}
		if (KPress)
		{
			if (smallPlayer == false)
			{
				coduoi = true;
			}
		}
		if (MPress)
		{
			coduoi = false;
			smallPlayer = true;
			_time = 0;

		}
		if (BPress)
		{

			om_rua = true;

		}
		else if (!BPress)
		{
			om_rua = false;
			if (player_state == OMRUA)
			{
				player_state = STAND;
			}
		}
		else
		{
			om_rua = false;
		}
		if (TPress)
		{
			player_alive = false;
		}
		if (coduoi)
		{
			if (HPress)
			{
				hit_brick = true;
				
				
			}
			else
			{
				hit_brick = false;
			}
		}
		if (x < 2000&&y<228)
		{
			player_alive = false;
		}
		if (XPress)
		{
			changelevel = 1;
			x = 100;
			y = 268;
			currentstate = 2;
		}
		
		if (reset_)
		{
			changelevel = 1;
			x = 10;
			y = 260;
			currentstate = 2;
			reset_ = false;
		}
		
		
		DWORD now = GetTickCount();
		


#pragma endregion 


#pragma region Giatoc
		
		if (!APress)
		{
			if (now-last_time >1000/30)
			{
				if (stand_right == true)
				{
					
					if (smallPlayer == false)
					{
						
						if (coduoi&&!om_rua)
						{
							player_coduoi_run_right->nextSprite();
							player_coduoi_stand_right->nextSprite();
							player_coduoi_flight_right->nextSprite();
							player_supper_coduoi_hit_turtle->setIndex(3);
							player_coduoi_acc->setIndex(2);
							this->player_coduoi_xyz->nextSprite();
							player_tran_right->nextSprite();
												
							
							
						}
						else if (om_rua&&coduoi)
						{
							///SUPPER
							
							///CODUOI
							player_coduoi_omrua_green_stand->setIndex(0);
							player_coduoi_omrua_red_stand->setIndex(0);

							player_coduoi_omrua_red_run_right->nextSprite();
							player_coduoi_omrua_green_run_right->nextSprite();
					
							
						}
						else if (om_rua&&!coduoi)
						{
							player_supper_omrua_green_stand->setIndex(1);
							player_supper_omrua_green_run_right->nextSprite();
							player_supper_omrua_red_run_right->nextSprite();
							player_supper_omrua_red_stand_right->nextSprite();
						}
						else
						{
							player_supper_run_right->nextSprite();
							player_supper_tand_right->nextSprite();
							player_supper_run_left->nextSprite();
							player_supper_coduoi_hit_turtle->setIndex(1);
							player_coduoi_acc->setIndex(0);
							player_super_tran->nextSprite();
							player_tran_right->nextSprite();
							
						}

					}
					else
					{

						player_small_run_right->nextSprite();
						player_small_jump_right->nextSprite();
						player_small_tand_right->nextSprite();
						player_small_hit_turtle->setIndex(0);
						player_tran_right->nextSprite();
					
						
						if (om_rua)
						{
							player_small_omrua_red_stand->setIndex(1);
							player_small_omrua_green_stand->setIndex(1);
							player_small_omrua_red_run_right->nextSprite();
							player_small_omrua_green_run_right->nextSprite();
						}
						

						
					}
				
					
					if (!player_alive)
					{
						//Die......................
						player_small_die->nextSprite();
					}
				}
				else
				{
					
					if (smallPlayer == false)
					{
						
						if (coduoi&&!om_rua)
						{
							player_coduoi_run_left->nextSprite();
							player_coduoi_stand_left->nextSprite();
							player_coduoi_flight_left->nextSprite();
							player_supper_coduoi_hit_turtle->setIndex(2);
							player_coduoi_acc->setIndex(3);
							this->player_coduoi_xyz->nextSprite();
							player_tran_left->nextSprite();
						}
						else if (om_rua&&coduoi)
						{
							player_coduoi_omrua_green_stand->setIndex(1);
							player_coduoi_omrua_red_stand->setIndex(1);

							player_coduoi_omrua_red_run_left->nextSprite();
							player_coduoi_omrua_green_run_left->nextSprite();
							
							
						}
						else if (!coduoi&&om_rua)
						{
							player_supper_omrua_green_stand->setIndex(0);
							player_supper_omrua_green_run_left->nextSprite();
							player_supper_omrua_red_run_left->nextSprite();
							player_supper_omrua_red_stand_left->nextSprite();
						}
						else
						{
							player_supper_run_left->nextSprite();
							player_supper_tand_left->nextSprite();
							player_supper_jump_left->nextSprite();
							player_supper_coduoi_hit_turtle->setIndex(0);
							player_coduoi_acc->setIndex(1);
							player_super_tran->nextSprite();
							player_tran_left->nextSprite();
							
							
						}


					}
					else
					{
						
						if (om_rua)
						{
							player_small_omrua_red_stand->setIndex(0);
							player_small_omrua_green_stand->setIndex(0);
							player_small_omrua_red_run_left->nextSprite();
							player_small_omrua_green_run_left->nextSprite();
						}
						else
						{
							player_small_run_left->nextSprite();
							player_small_jump_left->nextSprite();
							player_small_tand_left->nextSprite();
							player_small_hit_turtle->setIndex(1);
							player_tran_left->nextSprite();
							
						}
					}
					if (!player_alive)
					{
						player_small_die->nextSprite();
					}
				}
				last_time = now;
			}

		}
		else if (APress)
		{
			if (rightPress)
			{
				if (spacePress)
				{
					vx += 0.8f;

				}
				else
				{
					vx += 0.015;
				}


			}

			else if (leftPress)
			{
				if (spacePress)
				{
					vx -= 0.8f;

				}
				else
				{
					vx -= 0.015f;
				}

			}
			if (now - last_time > 1000 / 40)
			{
				if (stand_right == true)
				{

					if (smallPlayer == false)
					{
						if (coduoi)
						{
							player_coduoi_run_right->nextSprite();
							player_coduoi_stand_right->nextSprite();
							player_coduoi_flight_left->nextSprite();
							player_coduoi_acc->setIndex(2);
						}
						else if (om_rua == true)
						{
							player_supper_omrua_red_run_right->nextSprite();
							player_supper_omrua_red_stand_right->nextSprite();


						}
						else
						{
							player_supper_run_right->nextSprite();
							player_supper_tand_right->nextSprite();
							player_supper_run_left->nextSprite();
							player_coduoi_acc->setIndex(0);


						}

					}
					else
					{
						player_small_run_right->nextSprite();
						player_small_jump_right->nextSprite();
						player_small_tand_right->nextSprite();
						player_small_acc->setIndex(0);
					}
					if (!player_alive)
					{
						//Die......................
						player_small_die->nextSprite();
					}
				}
				else
				{

					if (smallPlayer == false)
					{
						if (coduoi)
						{
							player_coduoi_run_left->nextSprite();
							player_coduoi_stand_left->nextSprite();
							player_coduoi_flight_left->nextSprite();
							player_coduoi_acc->setIndex(3);
						}
						else if (om_rua == true)
						{
							player_supper_omrua_red_run_left->nextSprite();
							player_supper_omrua_red_stand_left->nextSprite();


						}
						else
						{
							player_supper_run_left->nextSprite();
							player_supper_tand_left->nextSprite();
							player_supper_jump_left->nextSprite();
							player_coduoi_acc->setIndex(1);
						}

					}
					else
					{
						player_small_run_left->nextSprite();
						player_small_jump_left->nextSprite();
						player_small_tand_left->nextSprite();
						player_small_acc->setIndex(1);


					}
					if (!player_alive)
					{
						player_small_die->nextSprite();
					}
				}
				last_time = now;
			}
		}
		
#pragma endregion	
		
		
	}
	else
	{
		if (_time > 3000)
		{
			
			
			player_alive = true;
			stand_right = true;
			smallPlayer = true;
			coduoi = false;
			number_live++;
			reset_player = true;
			_time = 0;
			x = startx;
			y = starty;
		
		

		}
		
		else if (_time > 2000 && _time < 3000)
		{
			
			vy= -2.0f;
			_time += time;
		
		}
		else if (_time > 1000 && _time < 2000)
		{
			vy = 1.0f;
			_time += time;
		}
		else
		{
			
			
			vx = 0;
			vy = 0;
			_time += time;
		}

	}
	if (down_h == false)
	{
		x += vx;
		y += vy;
	}
	
	before_x_col = x;
	if (player_alive)
	{
		updateBox();
	}
	else
	{
		box = Box(0, 0, 0, 0);
	}
	
	
}
void Player::drawPlayer(float  vpx, float  vpy)
{
	
	
	if (this->stand_right == true)
	{
		if (smallPlayer == true)
		{
			if (player_alive)
			{
				switch (player_state)
				{
				case STAND:
					if (om_rua)
					{
						if (om_red_turtle)
						{
							player_small_omrua_red_stand->renderSprite(x, y, vpx, vpy);
						}
						else if(om_green_turtle)
						{
							player_small_omrua_green_stand->renderSprite(x, y, vpx, vpy);
						}
					}
					else
					player_small_tand_right->renderSprite(x, y-1, vpx, vpy);
					break;
				case RUN:
					if (om_rua)
					{
						if (om_red_turtle)
						{
							player_small_omrua_red_run_right->renderSprite(x, y, vpx, vpy);
						}
						else if (om_green_turtle)
						{
							player_small_omrua_green_run_right->renderSprite(x, y, vpx, vpy);
						}

					
					}
					else

					player_small_run_right->renderSprite(x, y, vpx, vpy);
					break;
				case JUMP:
					if (om_rua)
					{
						if (om_red_turtle)
						{
							player_small_omrua_red_stand->renderSprite(x, y, vpx, vpy);
						}
						else if (om_green_turtle)
						{
							player_small_omrua_green_stand->renderSprite(x, y, vpx, vpy);
						}


					}
					else
					player_small_jump_right->renderSprite(x, y, vpx, vpy);
					break;
				case HIT_:
					player_small_hit_turtle->renderSprite(x, y, vpx, vpy);
					break;
				case ACCELERATION:
					player_small_acc->renderSprite(x, y, vpx, vpy);
					break;
				case TRAN:

					player_tran_right->renderSprite(x, y + 10, vpx, vpy);
					break;
				default:
					break;


				}
			}


			else
			{
				
				player_small_die->renderSprite(x, y, vpx, vpy);

			}
		}
		else
		{
			switch (player_state)
			{
			case RUN:
				if (coduoi&&!om_rua)
				{
					if (hit_brick == true)
					{
						this->player_coduoi_xyz->renderSprite(x, y, vpx, vpy);
					}
					else
					{
						player_coduoi_run_right->renderSprite(x, y, vpx, vpy);
					}
					

				}
				else if (coduoi&&om_rua)
				{
					if (om_red_turtle)
					{
						player_coduoi_omrua_red_run_right->renderSprite(x, y, vpx, vpy);

					}
					else if(om_green_turtle)
					{
						player_coduoi_omrua_green_run_right->renderSprite(x, y, vpx, vpy);
					}
				}
				else if (om_rua&&!coduoi)
				{
					if (om_red_turtle)
					{
						player_supper_omrua_red_run_right->renderSprite(x, y, vpx, vpy);
					}
					else if(om_green_turtle)
					{
						player_supper_omrua_green_run_right->renderSprite(x, y, vpx, vpy);
					}
					
				}
				else
				{
					player_supper_run_right->renderSprite(x, y, vpx, vpy);
				}
				break;
		
				
			case STAND:
				if (coduoi&&!om_rua)
				{
					if (hit_brick == true)
					{
						this->player_coduoi_xyz->renderSprite(x, y, vpx,vpy);
					}
					else
					{
						player_coduoi_stand_right->renderSprite(x, y, vpx, vpy);
					}
					
				}
				else if (coduoi&&om_rua)
				{
					if (om_red_turtle)
					{
						player_coduoi_omrua_red_stand->renderSprite(x, y, vpx, vpy);
					}
					else if (om_green_turtle)
					{
						player_coduoi_omrua_green_stand->renderSprite(x, y, vpx, vpy);
					}
				}
				else if (om_rua&&!coduoi)
				{
					if (om_red_turtle)
					{
						player_supper_omrua_red_stand_right->renderSprite(x, y, vpx, vpy);
					}
					else
					{
						player_supper_omrua_green_stand->renderSprite(x, y, vpx, vpy);
					}
					

				}
				else
				{
					player_supper_tand_right->renderSprite(x, y, vpx, vpy);
				}
				
				break;
			case JUMP:
				if (coduoi&&!om_rua)
				{
					if (hit_brick == true)
					{
						this->player_coduoi_xyz->renderSprite(x, y, vpx, vpy);
					}
					else
					{
						player_coduoi_jump_right->renderSprite(x, y, vpx, vpy);
					}
					
				}
				else if (coduoi&&om_rua)
				{
					if (om_red_turtle)
					{
						player_coduoi_omrua_red_stand->renderSprite(x, y, vpx, vpy);
					}
					else if (om_green_turtle)
					{
						player_coduoi_omrua_green_stand->renderSprite(x, y, vpx, vpy);
					}
				}
				else if (om_rua&&!coduoi)
				{
					if (om_red_turtle)
					{
						player_supper_omrua_red_stand_right->renderSprite(x, y, vpx, vpy);
					}
					else
					{
						player_supper_omrua_green_stand->renderSprite(x, y, vpx, vpy);
					}


				}
				else
				{
					player_supper_jump_right->renderSprite(x, y, vpx, vpy);
				}
				
				break;
			case FLIGHT:
				player_coduoi_flight_right->renderSprite(x, y, vpx, vpy);
				break;
			case HIT_:
				/*playerHit_Right_S->Render(x, y, vpx, vpy);*/
				player_supper_coduoi_hit_turtle->renderSprite(x, y, vpx, vpy);
				break;
			case ACCELERATION:
				player_coduoi_acc->renderSprite(x, y, vpx, vpy);
				break;
			case TRAN:
				if (col_with_enemy)
				{
					player_tran_right->renderSprite(x, y, vpx, vpy);
				}
				else
				{
					player_super_tran->renderSprite(x, y, vpx, vpy);
				}
		
				break;
			default:
				break;
			

			}

			
		}
	}
	else
	{
		if (player_alive)
		{

			if (this->smallPlayer == true)
			{
				switch (player_state)
				{
				case STAND:
					if (om_rua)
					{
						if (om_red_turtle)
						{
							player_small_omrua_red_stand->renderSprite(x, y, vpx, vpy);
						}
						else if (om_green_turtle)
						{
							player_small_omrua_green_stand->renderSprite(x, y, vpx, vpy);
						}


					}
					else

					player_small_tand_left->renderSprite(x, y-1, vpx, vpy);
					break;
				case RUN:
					if (om_rua)
					{
						if (om_red_turtle)
						{
							player_small_omrua_red_run_left->renderSprite(x, y, vpx, vpy);
						}
						else if (om_green_turtle)
						{
							player_small_omrua_green_run_left->renderSprite(x, y, vpx, vpy);
						}


					}
					else
					player_small_run_left->renderSprite(x, y, vpx, vpy);
					break;
				case JUMP:
					if (om_rua)
					{
						if (om_red_turtle)
						{
							player_small_omrua_red_stand->renderSprite(x, y, vpx, vpy);
						}
						else if (om_green_turtle)
						{
							player_small_omrua_green_stand->renderSprite(x, y, vpx, vpy);
						}


					}
					else
					player_small_jump_left->renderSprite(x, y, vpx, vpy);
					break;
				case HIT_:
					player_small_hit_turtle->renderSprite(x, y, vpx, vpy);
					break;
				case ACCELERATION:
					
					player_small_acc->renderSprite(x, y, vpx, vpy);
					break;

				case TRAN:
					player_tran_left->renderSprite(x, y + 10, vpx, vpy);
					break;
				default:
					break;


				}
			}
			else
			{
				switch (player_state)
				{
				case RUN:
					if (coduoi&&!om_rua)
					{
						if (hit_brick == true)
						{
							this->player_coduoi_xyz->renderSprite(x, y, vpx, vpy);
						}
						else
						{
							player_coduoi_run_left->renderSprite(x, y, vpx, vpy);
						}
						
						
					}
					else if (coduoi&&om_rua)
					{
						if (om_red_turtle)
						{
							player_coduoi_omrua_red_run_left->renderSprite(x, y, vpx, vpy);
						}
						else if (om_green_turtle)
						{
							player_coduoi_omrua_green_run_left->renderSprite(x, y, vpx, vpy);
						}
					}
					else if (om_rua&&!coduoi)
					{
						if (om_red_turtle)
						{
							player_supper_omrua_red_run_left->renderSprite(x, y, vpx, vpy);
						}
						else if (om_green_turtle)
						{
							player_supper_omrua_green_run_left->renderSprite(x, y, vpx, vpy);
						}

					}
					else
					{
						player_supper_run_left->renderSprite(x, y, vpx, vpy);
					}
				
					break;

				case STAND:
					if (coduoi&&!om_rua)
					{
						if (hit_brick == true)
						{
							this->player_coduoi_xyz->renderSprite(x, y, vpx, vpy);
						}
						else
						{
							player_coduoi_stand_left->renderSprite(x, y, vpx, vpy);
						}
						
					}
					else if (coduoi&&om_rua)
					{
						if (om_red_turtle)
						{
							player_coduoi_omrua_red_stand->renderSprite(x, y, vpx, vpy);

						}
						else if (om_green_turtle)
						{
							player_coduoi_omrua_green_stand->renderSprite(x, y, vpx, vpy);
						}

					}
					else if (om_rua&&!coduoi)
					{
						if (om_red_turtle)
						{
							player_supper_omrua_red_stand_left->renderSprite(x, y, vpx, vpy);

						}
						else if (om_green_turtle)
						{
							player_supper_omrua_green_stand->renderSprite(x, y, vpx, vpy);
						}
					
					}
					else
					{
						player_supper_tand_left->renderSprite(x, y, vpx, vpy);
					}

					break;
				case JUMP:
					if (coduoi&&!om_rua)
					{
						if (hit_brick == true)
						{
							this->player_coduoi_xyz->renderSprite(x, y, vpx, vpy);
						}
						else
						{
							player_coduoi_jump_left->renderSprite(x, y, vpx, vpy);
						}
						
					}
					else if (coduoi&&om_rua)
					{
						if (om_red_turtle)
						{
							player_coduoi_omrua_red_stand->renderSprite(x, y, vpx, vpy);
						}
						else
						{
							player_coduoi_omrua_green_stand->renderSprite(x, y, vpx, vpy);
						}
					}
					else if (om_rua&&!coduoi)
					{
						if (om_red_turtle)
						{
							player_supper_omrua_red_stand_left->renderSprite(x, y, vpx, vpy);
						}
						else
						{
							player_supper_omrua_green_stand->renderSprite(x, y, vpx, vpy);
						}
						
					}
					else
					{
						player_supper_jump_left->renderSprite(x, y, vpx, vpy);
					}
					
					break;
				case FLIGHT:
					player_coduoi_flight_left->renderSprite(x, y, vpx, vpy);
					break;
				case HIT_:
					/*playerHit_Left_S->Render(x, y, vpx, vpy);*/
					player_supper_coduoi_hit_turtle->renderSprite(x, y, vpx, vpy);
					break;
				case ACCELERATION:
					player_coduoi_acc->renderSprite(x, y, vpx, vpy);
					break;
				case TRAN:
					if (col_with_enemy)
					{
						player_tran_left->renderSprite(x, y, vpx, vpy);
					}
					else
					{
						player_super_tran->renderSprite(x, y, vpx, vpy);
					}
				
					break;
				default:
					break;


				}
			}
			
		}
		else
		{
			player_small_die->renderSprite(x, y, vpx, vpy);

		}

	}
	
	
}
void Player::updateBox()
{
	if (smallPlayer == true)
	{
		if (player_state == STAND||player_state==RUN)
		{
			box.x = x-6;
			box.y = y-7.5F;
			box.width = 12;
			box.height = 15;
			box.vx = vx;
			box.vy = vy;
		}
		if (player_state == JUMP)
		{
			box.x = x-8;
			box.y = y-8;
			box.width = NOMAL_SIZE;
			box.height = NOMAL_SIZE;
			box.vx = vx;
			box.vy = vy;
		}
	}
	else
	{
		if (om_rua)
		{

			box.x = x - 27 / 2;
			box.y = y - 27 / 2;
			box.width = 27;
			box.height = 27;
			box.vx = vx;
			box.vy = vy;
		}
				
		else
		{
			if (player_state == STAND || player_state == RUN)
			{

				if (!coduoi)
				{
					box.x = x - MATIO_TILE_WIDTH_STAND_SUPER / 2;
					box.y = y - MATIO_TILE_HEIGHT_STAND_SUPER / 2;
					box.width = MATIO_TILE_WIDTH_STAND_SUPER;
					box.height = MATIO_TILE_HEIGHT_STAND_SUPER;
					box.vx = vx;
					box.vy = vy;
				}
				else
				{
					
					if (hit_brick)
					{
						box.x = x - 28 / 2;
						box.y = y - 27 / 2;
						box.width = 28;
						box.height = 27;
						box.vx = vx;
						box.vy = vy;
					}
					else
					{
						box.x = x - 20 / 2;
						box.y = y - MATIO_TILE_HEIGHT_STAND_SUPER / 2;
						box.width = 20;
						box.height = MATIO_TILE_HEIGHT_STAND_SUPER;
						box.vx = vx;
						box.vy = vy;
					}
				}

			}
			else if (player_state == JUMP || player_state == HIT_ || player_state == OMRUA)
			{

				
				if (hit_brick)
				{
					box.x = x - 27 / 2;
					box.y = y - 27 / 2;
					box.width = 27;
					box.height = 27;
					box.vx = vx;
					box.vy = vy;
				}
				else
				{
					box.x = x - 8;
					box.y = y - 13;
					box.width = 16;
					box.height = 26;
					box.vx = vx;
					box.vy = vy;
				}

			}
			else if (player_state == FLIGHT)
			{
				box.x = x - 8;
				box.y = y - 13;
				box.width = 16;
				box.height = 26;
				box.vx = vx;
				box.vy = vy;
			}
			else if (player_state == ACCELERATION)
			{
				box.x = x - 8;
				box.y = y - 15;
				box.width = 16;
				box.height = 30;
				box.vx = vx;
				box.vy = vy;
			}
		}
		
	}


}

void Player::killPlayer()
{
	if (stand_right)
		vx = -3;
	else vx = -3;
	box = Box(0, 0, 0, 0);
}






