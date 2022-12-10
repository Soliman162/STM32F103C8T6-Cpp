#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "RCC_interface.hpp"
#include "RCC_private.hpp"
#include "RCC_config.hpp"

void RCC_voidCLKInit(void)
{
#ifdef  CLK_SOURCE

    #if CLK_SOURCE == HSE

      RCC_voidHSEBYPASS();
      RCC_voidSETAHB_Prescaller();
      RCC_voidSETAPB1_Prescaller();
      RCC_voidSETAPB2_Prescaller();
      SET_BIT( RCC->CFGR , SW_0);
      CLR_BIT( RCC->CFGR , SW_1);
      SET_BIT( RCC->CR , HSEON );

      while( (GET_BIT( RCC->CR , HSERDY )) == 0 );

    #elif CLK_SOURCE == HSI

      RCC_voidSETAHB_Prescaller();
      RCC_voidSETAPB1_Prescaller();
      RCC_voidSETAPB2_Prescaller();
      CLR_BIT( RCC->CFGR , SW_0);
      CLR_BIT( RCC->CFGR , SW_1);
      SET_BIT( RCC->CR , HSION );
      while( (GET_BIT( RCC->CR , HSIRDY )) == 0 );

    #elif CLK_SOURCE == PLL

      RCC_voidSETAHB_Prescaller();
      RCC_voidSETAPB1_Prescaller();
      RCC_voidSETAPB2_Prescaller();
      RCC_voidSETPLL_MULTIPLCATION_FACTOR();
      RCC_voidSETPLL_CLK_SOURCE();
      CLR_BIT( RCC->CFGR , SW_0);
      SET_BIT( RCC->CFGR , SW_1);
      SET_BIT( RCC->CR , PLLON );
      while( (GET_BIT( RCC->CR , PLLRDY )) == 0 );

    #endif
#endif
	/*init system clk*/
	for(u8 i=0;i<CLK_Used_NUM;i++)
	{
		SET_BIT( RCC->AHBENR_APB2ENR_APB1ENR[System_u8Clk_array[i][0]] , System_u8Clk_array[i][1] );
	}
	
}
void RCC_voidPeripheralCLKEnable( CLK_BUS Copy_u8BUS ,u8 Copy_u8Peripheral )
{
	SET_BIT( RCC->AHBENR_APB2ENR_APB1ENR[Copy_u8BUS] , Copy_u8Peripheral );
}

void RCC_voidPeripheralCLKDisable(  CLK_BUS Copy_u8BUS ,u8 Copy_u8Peripheral )
{
	CLR_BIT( RCC->AHBENR_APB2ENR_APB1ENR[Copy_u8BUS] , Copy_u8Peripheral );
}

inline void RCC_voidSETAHB_Prescaller(void){

    #ifdef AHB_PRESCALLER

      #if AHB_PRESCALLER ==  DIVIDEDBY_1

        CLR_BIT( RCC->CFGR , HPRE_7 );

      #elif AHB_PRESCALLER ==  DIVIDEDBY_2

        CLR_BIT( RCC->CFGR , HPRE_4 );
        CLR_BIT( RCC->CFGR , HPRE_5 );
        CLR_BIT( RCC->CFGR , HPRE_6 );
        SET_BIT( RCC->CFGR , HPRE_7 );

      #elif AHB_PRESCALLER ==  DIVIDEDBY_4

        SET_BIT( RCC->CFGR , HPRE_4 );
        CLR_BIT( RCC->CFGR , HPRE_5 );
        CLR_BIT( RCC->CFGR , HPRE_6 );
        SET_BIT( RCC->CFGR , HPRE_7 );

      #elif AHB_PRESCALLER ==  DIVIDEDBY_8

        CLR_BIT( RCC->CFGR , HPRE_4 );
        SET_BIT( RCC->CFGR , HPRE_5 );
        CLR_BIT( RCC->CFGR , HPRE_6 );
        SET_BIT( RCC->CFGR , HPRE_7 );

      #elif AHB_PRESCALLER ==  DIVIDEDBY_16

        SET_BIT( RCC->CFGR , HPRE_4 );
        SET_BIT( RCC->CFGR , HPRE_5 );
        CLR_BIT( RCC->CFGR , HPRE_6 );
        SET_BIT( RCC->CFGR , HPRE_7 );

      #elif AHB_PRESCALLER ==  DIVIDEDBY_64

        CLR_BIT( RCC->CFGR , HPRE_4 );
        CLR_BIT( RCC->CFGR , HPRE_5 );
        SET_BIT( RCC->CFGR , HPRE_6 );
        SET_BIT( RCC->CFGR , HPRE_7 );

      #elif AHB_PRESCALLER ==  DIVIDEDBY_128

        SET_BIT( RCC->CFGR , HPRE_4 );
        CLR_BIT( RCC->CFGR , HPRE_5 );
        SET_BIT( RCC->CFGR , HPRE_6 );
        SET_BIT( RCC->CFGR , HPRE_7 );

      #elif AHB_PRESCALLER ==  DIVIDEDBY_256

        CLR_BIT( RCC->CFGR , HPRE_4 );
        SET_BIT( RCC->CFGR , HPRE_5 );
        SET_BIT( RCC->CFGR , HPRE_6 );
        SET_BIT( RCC->CFGR , HPRE_7 );

      #elif AHB_PRESCALLER ==  DIVIDEDBY_512

        SET_BIT( RCC->CFGR , HPRE_4 );
        SET_BIT( RCC->CFGR , HPRE_5 );
        SET_BIT( RCC->CFGR , HPRE_6 );
        SET_BIT( RCC->CFGR , HPRE_7 );

      #endif
    #endif
}

inline void RCC_voidSETAPB1_Prescaller(void){

  #ifdef APB1_PRESCALLER

    #if APB1_PRESCALLER ==  DIVIDEDBY_1
        CLR_BIT( RCC->CFGR , PPRE1_10 );
    #elif DIVIDEDBY_2

        CLR_BIT( RCC->CFGR , PPRE1_8 );
        CLR_BIT( RCC->CFGR , PPRE1_9 );
        SET_BIT( RCC->CFGR , PPRE1_10 );

    #elif APB1_PRESCALLER ==  DIVIDEDBY_4

        SET_BIT( RCC->CFGR , PPRE1_8 );
        CLR_BIT( RCC->CFGR , PPRE1_9 );
        SET_BIT( RCC->CFGR , PPRE1_10 );

    #elif APB1_PRESCALLER == DIVIDEDBY_8

        CLR_BIT( RCC->CFGR , PPRE1_8 );
        SET_BIT( RCC->CFGR , PPRE1_9 );
        SET_BIT( RCC->CFGR , PPRE1_10 );

    #elif APB1_PRESCALLER == DIVIDEDBY_16

        SET_BIT( RCC->CFGR , PPRE1_8 );
        SET_BIT( RCC->CFGR , PPRE1_9 );
        SET_BIT( RCC->CFGR , PPRE1_10 );

    #endif
  #endif
}


inline void RCC_voidSETAPB2_Prescaller(void){

  #ifdef APB2_PRESCALLER

    #if APB2_PRESCALLER ==  DIVIDEDBY_1
        CLR_BIT( RCC->CFGR , PPRE2_13 );
    #elif APB2_PRESCALLER == DIVIDEDBY_2

        CLR_BIT( RCC->CFGR , PPRE2_11);
        CLR_BIT( RCC->CFGR , PPRE2_12);
        SET_BIT( RCC->CFGR , PPRE2_13 );

    #elif APB2_PRESCALLER == DIVIDEDBY_4

        SET_BIT( RCC->CFGR , PPRE2_11);
        CLR_BIT( RCC->CFGR , PPRE2_12);
        SET_BIT( RCC->CFGR , PPRE2_13 );

    #elif APB2_PRESCALLER == DIVIDEDBY_8

        CLR_BIT( RCC->CFGR , PPRE2_11 );
        SET_BIT( RCC->CFGR , PPRE2_12);
        SET_BIT( RCC->CFGR , PPRE2_13 );

    #elif APB2_PRESCALLER == DIVIDEDBY_16

        SET_BIT( RCC->CFGR , PPRE2_11);
        SET_BIT( RCC->CFGR , PPRE2_12);
        SET_BIT( RCC->CFGR , PPRE2_13 );

    #endif
  #endif

}

inline void RCC_voidSETPLL_CLK_SOURCE(void){

      #ifdef PLL_CLK_SOURCE

        #if   PLL_CLK_SOURCE == HSE

          RCC_voidHSEBYPASS();
          RCC_voidSETPLLPRESCALLER();
          SET_BIT( RCC->CFGR , PLLSRC_16);

        #elif   PLL_CLK_SOURCE == HSI

          CLR_BIT( RCC->CFGR , PLLSRC_16);

        #endif
      #endif
}

inline void RCC_voidSETPLLPRESCALLER(void){

    #ifdef PLL_PRESCALLER

        #if PLL_PRESCALLER == DIVIDEDBY_1

          CLR_BIT( RCC->CFGR ,PLLXTPRE_17);

        #elif PLL_PRESCALLER == DIVIDEDBY_2

          SET_BIT( RCC->CFGR ,PLLXTPRE_17);

        #endif
    #endif
}

inline void RCC_voidSETPLL_MULTIPLCATION_FACTOR(void){

  #ifdef  PLL_MULTIPLCATION_FACTOR

    #if     PLL_MULTIPLCATION_FACTOR == MUL_2

        CLR_BIT(RCC->CFGR , PLLMUL_18);
        CLR_BIT(RCC->CFGR , PLLMUL_19);
        CLR_BIT(RCC->CFGR , PLLMUL_20);
        CLR_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_3

        SET_BIT(RCC->CFGR , PLLMUL_18);
        CLR_BIT(RCC->CFGR , PLLMUL_19);
        CLR_BIT(RCC->CFGR , PLLMUL_20);
        CLR_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_4

        CLR_BIT(RCC->CFGR , PLLMUL_18);
        SET_BIT(RCC->CFGR , PLLMUL_19);
        CLR_BIT(RCC->CFGR , PLLMUL_20);
        CLR_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_5

        SET_BIT(RCC->CFGR , PLLMUL_18);
        SET_BIT(RCC->CFGR , PLLMUL_19);
        CLR_BIT(RCC->CFGR , PLLMUL_20);
        CLR_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_6

        CLR_BIT(RCC->CFGR , PLLMUL_18);
        CLR_BIT(RCC->CFGR , PLLMUL_19);
        SET_BIT(RCC->CFGR , PLLMUL_20);
        CLR_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_7

        SET_BIT(RCC->CFGR , PLLMUL_18);
        CLR_BIT(RCC->CFGR , PLLMUL_19);
        SET_BIT(RCC->CFGR , PLLMUL_20);
        CLR_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_8

        CLR_BIT(RCC->CFGR , PLLMUL_18);
        SET_BIT(RCC->CFGR , PLLMUL_19);
        SET_BIT(RCC->CFGR , PLLMUL_20);
        CLR_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_9

        SET_BIT(RCC->CFGR , PLLMUL_18);
        SET_BIT(RCC->CFGR , PLLMUL_19);
        SET_BIT(RCC->CFGR , PLLMUL_20);
        CLR_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_10

        CLR_BIT(RCC->CFGR , PLLMUL_18);
        CLR_BIT(RCC->CFGR , PLLMUL_19);
        CLR_BIT(RCC->CFGR , PLLMUL_20);
        SET_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_11

        SET_BIT(RCC->CFGR , PLLMUL_18);
        CLR_BIT(RCC->CFGR , PLLMUL_19);
        CLR_BIT(RCC->CFGR , PLLMUL_20);
        SET_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_12

        CLR_BIT(RCC->CFGR , PLLMUL_18);
        SET_BIT(RCC->CFGR , PLLMUL_19);
        CLR_BIT(RCC->CFGR , PLLMUL_20);
        SET_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_13

        SET_BIT(RCC->CFGR , PLLMUL_18);
        SET_BIT(RCC->CFGR , PLLMUL_19);
        CLR_BIT(RCC->CFGR , PLLMUL_20);
        SET_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_14

        CLR_BIT(RCC->CFGR , PLLMUL_18);
        CLR_BIT(RCC->CFGR , PLLMUL_19);
        SET_BIT(RCC->CFGR , PLLMUL_20);
        SET_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_15

        SET_BIT(RCC->CFGR , PLLMUL_18);
        CLR_BIT(RCC->CFGR , PLLMUL_19);
        SET_BIT(RCC->CFGR , PLLMUL_20);
        SET_BIT(RCC->CFGR , PLLMUL_21);

    #elif  PLL_MULTIPLCATION_FACTOR ==MUL_16

        CLR_BIT(RCC->CFGR , PLLMUL_18);
        SET_BIT(RCC->CFGR , PLLMUL_19);
        SET_BIT(RCC->CFGR , PLLMUL_20);
        SET_BIT(RCC->CFGR , PLLMUL_21);

    #endif
  #endif
}

inline void RCC_voidHSEBYPASS(void){

	#ifdef    HSE_TYPE

		#if (HSE_TYPE == CRYSTAL)
				CLR_BIT( RCC->CR, HSEBYP );

		#elif  (HSE_TYPE == RC)
				SET_BIT( RCC->CR, HSEBYP );

		#endif
	#endif
}
