#ifndef _MARIO_H_
#define _MARIO_H_

#include "Sprite.h"
#include "FKeyboard.h"

#include "Box.h"
#include "Objects.h"
class Player:public Objects
{
private :
	PlayerState player_state;
	bool stand_right;
	bool player_alive;
	int i;
	boolean is_col_with_flower;
	boolean reset_player;
	bool reset_;
	float before_x_col;
	float startx;
	float starty;
	float _time;
	DWORD last_time;
	boolean smallPlayer;
	boolean coduoi;
	float time_tranform;	
	float time_hit;
	bool om_red_turtle;
	bool om_green_turtle;
	bool jumped;
	float before_y_tran;
	bool change_level;
public :
	Player();
	~Player();
public :
	Player(LPDIRECT3DDEVICE9 d3ddv, float X,float Y);
public :
	///SPRITE SMALL
	Sprite*player_small_tand_left;
	Sprite*player_small_tand_right;
	Sprite*player_small_jump_left;
	Sprite*player_small_jump_right;
	Sprite*player_small_run_left;
	Sprite*player_small_run_right;
	Sprite*player_small_die;
	Sprite*player_small_acc;
	Sprite*player_tran_right;
	Sprite*player_tran_left;

	Sprite*player_small_omrua_red_run_left;
	Sprite*player_small_omrua_red_run_right;
	Sprite*player_small_omrua_red_stand;

	Sprite*player_small_omrua_green_run_left;
	Sprite*player_small_omrua_green_run_right;
	Sprite*player_small_omrua_green_stand;
public :
	///SPRITE SUPPER
	Sprite*player_supper_tand_left;
	Sprite*player_supper_tand_right;
	Sprite*player_supper_jump_left;
	Sprite*player_supper_jump_right;
	Sprite*player_supper_run_left;
	Sprite*player_supper_run_right;
	Sprite*player_supper_die;
	//
	Sprite*player_supper_omrua_red_run_left;
	Sprite*player_supper_omrua_red_run_right;
	Sprite*player_supper_omrua_red_stand_right;
	Sprite*player_supper_omrua_red_stand_left;
	//
	Sprite*player_supper_omrua_green_run_left;
	Sprite*player_supper_omrua_green_run_right;
	Sprite*player_supper_omrua_green_stand;
	Sprite*player_coduoi_xyz;
	Sprite*player_super_tran;


	
public:
	///SPRITE CODUOI
	Sprite*player_coduoi_stand_left;
	Sprite*player_coduoi_stand_right;
	Sprite*player_coduoi_jump_left;
	Sprite*player_coduoi_jump_right;
	Sprite*player_coduoi_run_left;
	Sprite*player_coduoi_run_right;
	Sprite*player_coduoi_die;
	Sprite*player_coduoi_flight_right;
	Sprite*player_coduoi_flight_left;
	Sprite*player_coduoi_acc;
	//
	Sprite*player_coduoi_omrua_red_run_left;
	Sprite*player_coduoi_omrua_red_run_right;
	Sprite*player_coduoi_omrua_red_stand;

	Sprite*player_coduoi_omrua_green_run_left;
	Sprite*player_coduoi_omrua_green_run_right;
	Sprite*player_coduoi_omrua_green_stand;

public :

	//SPRITE coduoi và small đá rùa
	Sprite*player_supper_coduoi_hit_turtle;
	Sprite*player_small_hit_turtle;
	Sprite*test;
public :
	bool om_rua;
	bool hit_brick;
	bool hit_buttonP;
	bool tran_;
	bool down_h;
	bool dow_up;
public:
	float vpy_before;
	float before_vp;
	float _time2;	
private :
	float before_col_v;
	float before_col_h;
	bool col_left;
	bool col_right;
	bool col_top;
	bool col_bootom;
	int number_live;
	int time_reset;
	bool col_with_enemy;
public:
	void initPlayer(LPDIRECT3DDEVICE9 d3ddv);
	void updatePlayer(FKeyboard*kbd, float vpx, float vpy,double time);
	void updateViewPort(float *vpx, float * vpy,float time);
	void drawPlayer(float  vpx, float vpy);
	void updateBox();
	void killPlayer();
	

public :
	void setState( PlayerState state)
	{
		this->player_state = state;
	}
	PlayerState getState()
	{
		return this->player_state;
	}
	boolean getReset()
	{
		return reset_player;
	}
	void setReset(boolean reset)
	{
		this->reset_player = reset;
	}
	void setAlive(bool alive)
	{
		this->player_alive = alive;
	}
	boolean getAlive()
	{
		return player_alive;
	}
	boolean getColWithFlower()
	{
		return is_col_with_flower;
	}
	void setColWithFlower(boolean col)
	{
		this->is_col_with_flower = col;
	}
	float getBeforeXCol()
	{
		return before_x_col;
	}
	boolean getSmallPlayer()
	{
		return smallPlayer;
	}
	void setSmallPlayer(boolean _small)
	{
		this->smallPlayer = _small;
	}
	boolean getCoDuoi()
	{
		return this->coduoi;
	}
	void setCoDuoi(boolean coduoi)
	{
		this->coduoi = coduoi;
	}
	bool getOmRua()
	{
		return om_rua;
	}
	void setOmRua(bool omrua)
	{
		this->om_rua = omrua;
	}
public :
		void setOmRedTurtle(bool omred)
		{
			this->om_red_turtle = omred;
		}
		void setOmGreenTurtle(bool omgreen)
		{
			this->om_green_turtle = omgreen;
		}
		void setHitBrick(bool hit_brick)
		{
			this->hit_brick == hit_brick;
		}
		
		bool getHitBrick()
		{
			return hit_brick;
		}
		bool getStandRight()
		{
			return this->stand_right;
		}
		bool getButtonP()
		{
			return hit_buttonP;
		}
		void setButtonP()
		{
			this->hit_buttonP = true;
		}
		void setTran(bool x)
		{
			this->tran_=x;
		}
		void setColDown(bool)
		{
			down_h = true;
		}
		void setDownUp(bool)
		{
			dow_up = true;
		}


public :
	void setColLeft(bool col_left)
	{
		this->col_left = col_left;
	}
	void setColRight(bool col_right)
	{
		this->col_right = col_right;
	}
	void setColBootom(bool col_bottom)
	{
		this->col_bootom = col_bottom;
	}
	bool getColLeft()
	{
		return col_left;
	}
	bool getColRight()
	{
		return col_right;
	}
	void setReset(bool reset_)
	{
		this->reset_ = reset_;
	}
	void setNumberLive(int number)
	{
		this->number_live = number;
	}
	int getNumberLive()
	{
		return number_live;
	}
	void setWithEnemy(bool col_enemy)
	{
		this->col_with_enemy = col_enemy;
	}
	
		

};
#endif