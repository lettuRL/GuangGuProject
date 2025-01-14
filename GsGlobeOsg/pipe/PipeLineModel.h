# i f n d e f   G E O G L O B E _ P I P E _ P I P E L I N E M O D E L  
 # d e f i n e   G E O G L O B E _ P I P E _ P I P E L I N E M O D E L   1  
 # i n c l u d e < o s g / P a g e d L O D >  
 # i n c l u d e   < P i p e / P i p e O p t i o n s . h >  
  
 # i n c l u d e   < o s g / P a g e d L O D >  
 # i n c l u d e   < T o o l / G l o b a l S e t t i n g . h >  
 n a m e s p a c e   G e o G l o b e  
 {  
 	 n a m e s p a c e   P i p e  
 	 {  
  
 	 	 c o n s t   o s g : : V e c 3   A x i s _ X   =   o s g : : V e c 3 d ( 1 . 0 , 0 . 0 , 0 . 0 ) ;  
 	 	 c o n s t   o s g : : V e c 3   A x i s _ Y   =   o s g : : V e c 3 d ( 0 . 0 , 1 . 0 , 0 . 0 ) ;  
 	 	 c o n s t   o s g : : V e c 3   A x i s _ Z   =   o s g : : V e c 3 d ( 0 . 0 , 0 . 0 , 1 . 0 ) ;  
        
        
 / / ck�eb_�{�k�vpenc�~�g��v�c�b�vG e o G l o b e �Nx 
 	 	 s t r u c t   R e c t S i z e  
 	 	 {  
 	 	 	 d o u b l e   m _ H e i g h t ;  
 	 	 	 d o u b l e   m _ W i d t h ;  
 	 	 	 v o i d   S e t S i z e ( d o u b l e   d b L e n , d o u b l e   d b W i d t h )  
 	 	 	 {  
 	 	 	 	 m _ H e i g h t   =   d b L e n ;  
 	 	 	 	 m _ W i d t h   =   d b W i d t h ;  
 	 	 	 }  
 	 	 } ;  
  
 	 	 u n i o n   P i p e S i z e  
 	 	 {  
 	 	 	 R e c t S i z e   r e c t S i z e ; / / � � � � � � � � � � � �  
 	 	 	 d o u b l e   d b R a d i u s ; / / � � � � � � � �  
 	 	 } ;  
  
 / * �{�k!j�W* /  
 	 	 c l a s s   P i p e L i n e M o d e l   :   p u b l i c   o s g : : L O D  
 	 	 {  
 	 	 p u b l i c :  
  
 / * �{�k!j�W* /  
 	 	 	 P i p e L i n e M o d e l O p t i o n s *   _ o p t i o n s ;  
 / * �{�k-N�_�p�~�~�^* /  
 	 	 	 o s g : : V e c 3 d                         _ c e n t e r C a r t ;  
 / * �{�k'Y\* /  
 	 	 	 P i p e S i z e                             _ s i z e ;  
 / * *b4Y��^* /  
 	 	 	 d o u b l e                                 _ c u t L e n ;  
 / * �{�k��r�* /  
 	 	 	 o s g : : V e c 4 d                         _ c o l o r ;  
 	 	 	 o s g : : r e f _ p t r < o s g : : M a t e r i a l >   _ m a t e r i a l ;  
  
  
 	 	 	 P i p e L i n e M o d e l ( P i p e L i n e M o d e l O p t i o n s *   o p t i o n s )  
 	 	 	 {  
 	 	 	 	 _ o p t i o n s = o p t i o n s ;  
 	 	 	 	 s t r i n g s t r e a m   s s ;  
 	 	 	 	 s s < < o p t i o n s - > _ f e a t u r e I D ;  
 	 	 	 	 s e t N a m e ( s s . s t r ( ) ) ;  
 	 	 	 	 _ c e n t e r C a r t = _ o p t i o n s - > _ m o d e l C a r t ;  
 / / $R�e:N�v�{؏/fW�{ 
 	 	 	 	 s w i t c h ( o p t i o n s - > _ s e c t i o n T y p e )  
 	 	 	 	 {  
 / / W�{���SJS�_ 
 	 	 	 	 c a s e   e C i r c l e :  
 	 	 	 	 	 {  
 	 	 	 	 	 	 P i p e S i z e   s i z e ;  
 	 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � m m  
 	 	 	 	 	 	 s i z e . d b R a d i u s   =   ( o p t i o n s - > _ d i a m e t e r / 2 ) * 0 . 0 0 1 ;  
  
  
 	 	 	 	 	 	 _ s i z e   =   s i z e ;  
 	 	 	 	 	 	 _ c u t L e n   =   s i z e . d b R a d i u s / 2 ;  
 	 	 	 	 	 }  
 	 	 	 	 	 b r e a k ;  
 / / �v�{���S��[ 
 	 	 	 	 c a s e   e R e c t :  
 	 	 	 	 	 {  
 	 	 	 	 	 	 P i p e S i z e   s i z e ;  
 	 	 	 	 	 	 s i z e . r e c t S i z e . m _ H e i g h t   =   o p t i o n s - > _ h e i g h t * 0 . 0 0 1 ;  
 	 	 	 	 	 	 s i z e . r e c t S i z e . m _ W i d t h   =   o p t i o n s - > _ w i d t h * 0 . 0 0 1 ;  
 	 	 	 	 	 	 _ s i z e   =   s i z e ;  
 	 	 	 	 	 	 _ c u t L e n   = (   ( s i z e . r e c t S i z e . m _ H e i g h t > s i z e . r e c t S i z e . m _ W i d t h ) ? s i z e . r e c t S i z e . m _ H e i g h t : s i z e . r e c t S i z e . m _ W i d t h ) / 2 ;  
 	 	 	 	 	 }  
 	 	 	 	 	 b r e a k ;  
 	 	 	 	 }  
  
 / / �g�^�{�k!j�W 
 	 	 	 	 b u i l d P i p e L i n e M o d e l ( ) ;  
  
 	 	 	 }  
 / / ���{*j*bb��vv��p, �v�c�b�vG e o G l o b e �Nx 
 	 	         v o i d   c a l c u S e c t i o n V e r t i c e s ( s t d : : v e c t o r < o s g : : V e c 3 > &   v S e c t i o n V e r t i c e s , i n t   n S l i c e , e n u m C r o s s S e c t i o n T y p e   e S h a p e , P i p e S i z e   p i p e S i z e )  
 	 	 	 {  
  
 	 	 	 	 s w i t c h ( e S h a p e )  
 	 	 	 	 {  
 / / �v�{�g�^�e�l 
 	 	 	 	 c a s e   e R e c t :  
 	 	 	 	 	 {  
 	 	 	 	 	 	 f l o a t   d b L e n   =   p i p e S i z e . r e c t S i z e . m _ H e i g h t ;  
 	 	 	 	 	 	 f l o a t   d b W i d t h   =   p i p e S i z e . r e c t S i z e . m _ W i d t h ;  
  
 	 	 	 	 	 	 / / v S e c t i o n V e r t i c e s . r e s i z e ( 4 ) ;  
 	 	 	 	 	 	 v S e c t i o n V e r t i c e s . p u s h _ b a c k ( o s g : : V e c 3 ( d b L e n / 2 , d b W i d t h / 2 , 0 . 0 ) ) ;  
 	 	 	 	 	 	 v S e c t i o n V e r t i c e s . p u s h _ b a c k ( o s g : : V e c 3 ( - d b L e n / 2 , d b W i d t h / 2 , 0 . 0 ) ) ;  
 	 	 	 	 	 	 v S e c t i o n V e r t i c e s . p u s h _ b a c k ( o s g : : V e c 3 ( - d b L e n / 2 , - d b W i d t h / 2 , 0 . 0 ) ) ;  
 	 	 	 	 	 	 v S e c t i o n V e r t i c e s . p u s h _ b a c k ( o s g : : V e c 3 ( d b L e n / 2 , - d b W i d t h / 2 , 0 . 0 ) ) ;  
 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 }  
 / / W�{�g�^�e�l 
 	 	 	 	 c a s e   e C i r c l e :  
 	 	 	 	 	 {  
 	 	 	 	 	 	 d o u b l e   d R a d i u s   =   p i p e S i z e . d b R a d i u s ;  
 	 	 	 	 	 	 o s g : : V e c 3   v e r t e x ;  
 	 	 	 	 	 	 f l o a t   a n g l e   =   0 . 0 ;  
 	 	 	 	 	 	 f o r   ( i n t   i = 0 ; i < n S l i c e ; i + +   )  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 v e r t e x . x ( )   =   c o s f ( a n g l e )   *   d R a d i u s ;  
 	 	 	 	 	 	 	 v e r t e x . y ( )   =   s i n f ( a n g l e )   *   d R a d i u s ;  
 	 	 	 	 	 	 	 v e r t e x . z ( )   = 0   ;  
 	 	 	 	 	 	 	 v S e c t i o n V e r t i c e s . p u s h _ b a c k ( v e r t e x ) ;  
 	 	 	 	 	 	 	 a n g l e   + =   2 * o s g : : P I / n S l i c e ;  
 	 	 	 	 	 	 }  
 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 }  
 	 	 	 	 d e f a u l t :  
 	 	 	 	 	 b r e a k ;  
 	 	 	 	 }  
 	 	 	 	 / / r e t u r n   N U L L ;  
 	 	 	 }  
  
 / / �N,g0WX[-N���S�{�~�vPg(��Oo` 
 	 	 	 v o i d   g e t S y m b o l F r o m L o c a l ( )  
 	 	 	 {  
 	 	 	 	 s t d : : s t r i n g   p i p e S y m b o l N a m e = _ o p t i o n s - > c r e a t e M a t e r i a l N a m e ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	  
  
 	 	 	 	 o s g : : r e f _ p t r < o s g : : O b j e c t >   o b j = (   G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ m e m C a c h e - > g e t O b j e c t F r o m C a c h e ( p i p e S y m b o l N a m e ) ) ;  
 	 	 	 	 _ m a t e r i a l = ( o s g : : M a t e r i a l * ) ( o b j . g e t ( ) ) ;  
  
 	 	 	 	 i f   ( ! o b j . v a l i d ( ) )  
 	 	 	 	 {  
 	 	 	 	 	 i n t   s i z e ;  
 	 	 	 	 	 c h a r *   d a t a ;  
 	 	 	 	 	 _ o p t i o n s - > _ d a t a B a s e - > _ s y m D B - > Q u e r y S i n g l e K e y V a l u e T a b l e ( " M o d e l S y m b o l " , _ o p t i o n s - > _ m o d e l G e o m e t r y I D , s i z e , & d a t a ) ;  
  
 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 	 B u f f e r   t e m p B u f ( d a t a + 5 ,   s i z e ) ;  
 	 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 }  
  
 	 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 _ m a t e r i a l   =   n e w   o s g : : M a t e r i a l ( ) ;  
 	 	 	 	 	 _ m a t e r i a l - > s e t A m b i e n t ( _ m a t e r i a l - > F R O N T _ A N D _ B A C K ,   _ c o l o r * 0 . 5 ) ;  
 	 	 	 	 	 _ m a t e r i a l - > s e t D i f f u s e ( _ m a t e r i a l - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 _ m a t e r i a l - > s e t S p e c u l a r ( _ m a t e r i a l - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 / / 	 	 	 m - > s e t E m i s s i o n ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 _ m a t e r i a l - > s e t S h i n i n e s s ( _ m a t e r i a l - > F R O N T _ A N D _ B A C K ,   3 2 . 0 ) ;  
  
  
 	 	 	 	 	 G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ m e m C a c h e - > a d d O b j e c t T o C a c h e ( p i p e S y m b o l N a m e , _ m a t e r i a l ) ;  
 	 	 	 	 	 / / G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . i n s e r t ( m a k e _ p a i r ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D , _ c o l o r ) ) ;  
 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
  
 	 	 	 	 }  
 	 	 	 	 e l s e  
 	 	 	 	 {  
 	 	 	 	 	 i n t   a = 0 ;  
 	 	 	 	 }  
  
  
  
 	 	 	 	 t h i s - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t A t t r i b u t e A n d M o d e s ( _ m a t e r i a l ,   o s g : : S t a t e A t t r i b u t e : : O N   |   o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D   ) ;  
  
  
  
 	 	 	 }  
  
 	 	 	 v o i d   s e l e c t ( b o o l   s e l e c t )  
 	 	 	 {  
 	 	 	 	 i f   ( s e l e c t )  
 	 	 	 	 {  
 	 	 	 	 	 o s g : : r e f _ p t r < o s g : : M a t e r i a l >   m   =   n e w   o s g : : M a t e r i a l ( ) ;  
 	 	 	 	 	 m - > s e t A m b i e n t ( m - > F R O N T _ A N D _ B A C K ,   o s g : : V e c 4 d ( 1 , 1 , 0 , 1 ) ) ;  
 	 	 	 	 	 m - > s e t D i f f u s e ( m - > F R O N T _ A N D _ B A C K ,   o s g : : V e c 4 d ( 1 , 1 , 0 , 1 ) ) ;  
 	 	 	 	 	 m - > s e t S p e c u l a r ( m - > F R O N T _ A N D _ B A C K ,   o s g : : V e c 4 d ( 1 , 1 , 0 , 1 ) ) ;  
 	 	 	 	 	 m - > s e t E m i s s i o n ( m - > F R O N T _ A N D _ B A C K ,   o s g : : V e c 4 d ( 1 , 1 , 0 , 1 ) ) ;  
 	 	 	 	 	 m - > s e t S h i n i n e s s ( m - > F R O N T _ A N D _ B A C K ,   3 2 . 0 ) ;  
 	 	 	 	 	 t h i s - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t A t t r i b u t e A n d M o d e s ( m ,   o s g : : S t a t e A t t r i b u t e : : O N   |   o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D   ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e  
 	 	 	 	 {  
  
 	 	 	 	 	 t h i s - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t A t t r i b u t e A n d M o d e s ( _ m a t e r i a l ,   o s g : : S t a t e A t t r i b u t e : : O N   |   o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D   ) ;  
 	 	 	 	 }  
 	 	 	 }  
 / * �Ng�R-N�_0R�{�k��r�* /  
 	 	 	 v o i d   g e t S y m b o l F r o m S e r v i c e ( )  
 	 	 	 {  
 	 	 	 	 s t d : : s t r i n g   p i p e S y m b o l N a m e = _ o p t i o n s - > c r e a t e M a t e r i a l N a m e ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	  
  
 	 	 	 	 o s g : : r e f _ p t r < o s g : : O b j e c t >   o b j = (   G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ m e m C a c h e - > g e t O b j e c t F r o m C a c h e ( p i p e S y m b o l N a m e ) ) ;  
 	 	 	 	 _ m a t e r i a l = ( o s g : : M a t e r i a l * ) ( o b j . g e t ( ) ) ;  
  
 	 	 	 	 i f   ( ! o b j . v a l i d ( ) )  
 	 	 	 	 {  
 	 	 	 	 c h a r *   d a t a ;  
 	 	 	 	 i n t       d a t a L e n ;  
 	 	 	 	 i f ( _ o p t i o n s - > _ c a c h e - > r e a d D a t a F r o m C a c h e ( p i p e S y m b o l N a m e , d a t a L e n , & d a t a ) )  
 	 	 	 	 {  
 	 	 	 	 	 i f   ( d a t a L e n ! = 0 )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 	 	 B u f f e r   t e m p B u f ( d a t a + 2 4 ,   d a t a L e n - 2 4 ) ;  
 	 	 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 	 }  
  
 	 	 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 }  
  
 	 	 	 	 	 d e l e t e   [ ] d a t a ;  
 	 	 	 	 }  
 	 	 	 	 e l s e  
 	 	 	 	 {  
 	 	 	 	 	 s t d : : s t r i n g   S y m b o l U r l = c r e a t S y m b o l U R L ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 D o w n l o a d   d l ;  
 	 	 	 	 	 i f ( ! d l . d o w n l o a d D a t a ( S y m b o l U r l ) )  
 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 / / 	 / /       s t d : : s t r i n g 	 t i l e D a t a = o s g E a r t h : : U R I ( t i l e U r l . c _ s t r ( ) ) . g e t S t r i n g ( ) ;  
  
  
 	 	 	 	 	 i f   ( d l . s i z e ! = 0 )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 _ o p t i o n s - > _ c a c h e - > w r i t e D a t a T o C a c h e ( p i p e S y m b o l N a m e , d l . s i z e , c o n s t _ c a s t < c h a r   * > ( d l . d a t a ) ) ;  
 	 	 	 	 	 }  
  
  
 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 	 B u f f e r   t e m p B u f ( c o n s t _ c a s t < c h a r   * > ( d l . d a t a + 2 4 ) ,   d l . s i z e - 2 4 ) ;  
  
  
 	 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 }  
  
 	 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 / / G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . i n s e r t ( m a k e _ p a i r ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D , _ c o l o r ) ) ;  
 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 }  
  
  
 	 	 	 	 	 _ m a t e r i a l   =   n e w   o s g : : M a t e r i a l ( ) ;  
 	 	 	 	 	 _ m a t e r i a l - > s e t A m b i e n t ( _ m a t e r i a l - > F R O N T _ A N D _ B A C K ,   _ c o l o r * 0 . 5 ) ;  
 	 	 	 	 	 _ m a t e r i a l - > s e t D i f f u s e ( _ m a t e r i a l - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 _ m a t e r i a l - > s e t S p e c u l a r ( _ m a t e r i a l - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 / / 	 	 	 m - > s e t E m i s s i o n ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 _ m a t e r i a l - > s e t S h i n i n e s s ( _ m a t e r i a l - > F R O N T _ A N D _ B A C K ,   3 2 . 0 ) ;  
  
  
 	 	 	 	 	 G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ m e m C a c h e - > a d d O b j e c t T o C a c h e ( p i p e S y m b o l N a m e , _ m a t e r i a l ) ;  
  
  
  
 	 	 	 	 }  
  
  
  
  
  
 / / &TRb`Y:N�S�YPg(� 
 	 	 	 	 t h i s - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t A t t r i b u t e A n d M o d e s ( _ m a t e r i a l ,   o s g : : S t a t e A t t r i b u t e : : O N   |   o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D   ) ;  
  
  
  
 	 	 	 }  
  
 / / ���{�{�~�v�el��w5�, �v�c�b�vG e o G l o b e �v�Nx 
 	 	 	 o s g : : M a t r i x   c a l c u R o t a t e M a t r i x ( o s g : : V e c 3 d   r e f e n c e V e c   / * � � � � � � � � � � � � � � � � � � � � * / , o s g : : V e c 3 d   t r a n s V e c   / * � � � � � � � � � � � � � � � � � � * / )  
 	 	 	 {  
 	 	 	 	 o s g : : V e c 3 d   v R o t a t e A x i s ; / / � � � � � � � � � � � � � �  
  
 	 	 	 	 r e f e n c e V e c . n o r m a l i z e ( ) ;  
 	 	 	 	 / / D 3 D X V e c 3 N o r m a l i z e ( & r e f e n c e V e c , & r e f e n c e V e c ) ;  
 	 	 	 	 / / D 3 D X V e c 3 C r o s s ( & v R o t a t e A x i s , & t r a n s V e c , & r e f e n c e V e c ) ;  
 	 	 	 	 v R o t a t e A x i s = r e f e n c e V e c ^ t r a n s V e c ;  
  
  
 	 	 	 	 f l o a t   f D o t   =   t r a n s V e c * r e f e n c e V e c ;  
 	 	 	 	 f l o a t   f v C y l i n d e r L e n   =   t r a n s V e c . l e n g t h ( ) ;  
 	 	 	 	 f l o a t   f L i n e L e n   =     r e f e n c e V e c . l e n g t h ( ) ;  
 	 	 	 	 d o u b l e   d A n g e l   =     a c o s ( f D o t / ( f v C y l i n d e r L e n * f L i n e L e n ) ) ;  
  
 	 	 	 	 o s g : : M a t r i x   r o t M a t r i x ;  
 	 	 	 	 r o t M a t r i x . s e t R o t a t e ( o s g : : Q u a t ( - d A n g e l , v R o t a t e A x i s ) ) ;  
 	 	 	 / / 	 o s g : : Q u a t ( )  
 	 	 	 	 / / D 3 D X M a t r i x R o t a t i o n A x i s ( & r o t M a t r i x , & v R o t a t e A x i s , d A n g e l ) ; / / � � � � � � � �  
  
 	 	 	 	 r e t u r n   r o t M a t r i x ;  
 	 	 	 }  
 / / ���{�{�~�v�el��w5�, �v�c�b�vG e o G l o b e �v�Nx 
 	 	 	 o s g : : M a t r i x   c a l c u R o t a t e M a t r i x ( c o n s t   s t d : : v e c t o r < o s g : : V e c 3 d >   & v R e f e r e n c e D i r , c o n s t   s t d : : v e c t o r < o s g : : V e c 3 d >   & v T r a n s f o r m D i r )  
 	 	 	 {  
 	 	 	 	 o s g : : M a t r i x     r e s M a t r i x ;  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 o s g : : M a t r i x   r o t a t e M a t r i x , r o t a t e M a t r i x 1 ;  
 	 	 	 	 r o t a t e M a t r i x   =   c a l c u R o t a t e M a t r i x ( v R e f e r e n c e D i r [ 0 ] , v T r a n s f o r m D i r [ 0 ] ) ;  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 o s g : : V e c 3 d   v e c T r a n s   ;  
 	 	 	 	 v e c T r a n s = v T r a n s f o r m D i r [ 1 ] * r o t a t e M a t r i x ;  
 	 	 	 	 / / D 3 D X V e c 3 T r a n s f o r m N o r m a l ( & v e c T r a n s , & v T r a n s f o r m D i r [ 1 ] , & r o t a t e M a t r i x ) ;  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 r o t a t e M a t r i x 1   =   c a l c u R o t a t e M a t r i x ( v R e f e r e n c e D i r [ 1 ] , v e c T r a n s ) ;  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 r e s M a t r i x = r o t a t e M a t r i x * r o t a t e M a t r i x 1 ;  
 	 	 	 	 / / D 3 D X M a t r i x M u l t i p l y ( & r e s M a t r i x , & r o t a t e M a t r i x , & r o t a t e M a t r i x 1 ) ;  
 	 	 	 	 r e t u r n   r e s M a t r i x ;  
 	 	 	 }  
 / / ���{�{�~�vs^�y�w5�, �v�c�b�vG e o G l o b e �v�Nx 
 	 	 	 o s g : : M a t r i x   c a l c u T r a n f o r m M a t r i x ( e n u m C r o s s S e c t i o n T y p e   e S h a p e , c o n s t   o s g : : V e c 3 d   & p i p e L i n e D i r ,   o s g : : V e c 3 d   & c e n t e r P o s D K E )  
 	 	 	 {  
 	 	 	 	 s w i t c h ( e S h a p e )  
 	 	 	 	 {  
 	 	 	 	 c a s e   e R e c t :  
 	 	 	 	 	 {  
 	 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 	 	 o s g : : V e c 3   o u t D i r = c e n t e r P o s D K E ;  
 	 	 	 	 	 	 o u t D i r . n o r m a l i z e ( ) ;  
 	 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � ? 
 	 	 	 	 	 	 / / D 3 D X V e c 3 N o r m a l i z e ( & o u t D i r , & D 3 D X V E C T O R 3 ( c e n t e r P o s D K E . x , c e n t e r P o s D K E . y , c e n t e r P o s D K E . z ) ) ;  
 	 	 	 	 	 	  
 	 	 	 	 	 	 o u t D i r = p i p e L i n e D i r ^ o u t D i r ;  
 	 	 	 	 	 	 / / D 3 D X V e c 3 C r o s s ( & o u t D i r , & p i p e L i n e D i r , & o u t D i r ) ;  
 	 	 	 	 	 	 v e c t o r < o s g : : V e c 3 d >   v R e f e r e n c e D i r , v T r a n s D i r ;  
 	 	 	 	 	 	 v R e f e r e n c e D i r . r e s i z e ( 2 ) ;  
 	 	 	 	 	 	 v R e f e r e n c e D i r [ 0 ]   =   p i p e L i n e D i r ;  
 	 	 	 	 	 	 v R e f e r e n c e D i r [ 1 ]   =   o u t D i r ;  
 	 	 	 	 	 	 v T r a n s D i r . r e s i z e ( 2 ) ;  
 	 	 	 	 	 	 v T r a n s D i r [ 0 ]   =   A x i s _ Z ;  
 	 	 	 	 	 	 v T r a n s D i r [ 1 ]   =   A x i s _ X ;  
 	 	 	 	 	 	 r e t u r n   c a l c u R o t a t e M a t r i x ( v R e f e r e n c e D i r , v T r a n s D i r ) ;  
 	 	 	 	 	 }  
 	 	 	 	 c a s e   e C i r c l e :  
 	 	 	 	 	 {  
 	 	 	 	 	 	 r e t u r n   c a l c u R o t a t e M a t r i x ( p i p e L i n e D i r , A x i s _ Z ) ;  
 	 	 	 	 	 }  
 	 	 	 	 d e f a u l t :  
 	 	 	 	 	 b r e a k ;  
 	 	 	 	 }  
  
 	 	 	 	 o s g : : M a t r i x   m a t i x ;  
 	 	 	 	 / / D 3 D X M a t r i x I d e n t i t y ( & m a t i x ) ;  
 	 	 	 	 r e t u r n   m a t i x ;  
 	 	 	 }  
  
 / / 9hnc*j*bb�v��p�S*j*bb�*Npe���{@b	gv��p��v�c�bG e o G l o b e -N�v�Nx 
 	 	 	 v o i d   c a l c u V e r t e x ( o s g : : V e c 3 A r r a y *   v P i p e V e r t i c e s ,   i n t   n S t a c k , o s g : : V e c 3 d   c e n t e r P o s D K E , e n u m C r o s s S e c t i o n T y p e   e S h a p e ,  
 	 	 	 	 c o n s t   s t d : : v e c t o r < o s g : : V e c 3 > &   v S e c t i o n V t , o s g : : V e c 3 d   s t a r t C a r t , o s g : : V e c 3 d   e n d C a r t )  
 	 	 	 {  
 	 	 	 	  
 	 	 	 	 d o u b l e   d b T r a n s X , d b T r a n s Y , d b T r a n s Z ;  
 	 	 	 	 o s g : : M a t r i x   T r a n s l a t e M a t r i x ;  
 	 	 	 	 o s g : : M a t r i x   r o t a t e M a t r i x ;  
 	 	 	 	 o s g : : M a t r i x   r e s u l t M a t r i x ;  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � ? 
 	 	 	 	 o s g : : V e c 3 d   p i p e L i n e D i r     =   e n d C a r t   -   s t a r t C a r t ;  
 	 	 	 	 r o t a t e M a t r i x   =   c a l c u T r a n f o r m M a t r i x ( e S h a p e , p i p e L i n e D i r , c e n t e r P o s D K E ) ;  
  
 	 	 	 	 o s g : : V e c 3 d   v N o r m a l i z e L i n e D i r = p i p e L i n e D i r ;  
 	 	 	 	 v N o r m a l i z e L i n e D i r . n o r m a l i z e ( ) ;  
 	 	 	 	 / / D 3 D X V e c 3 N o r m a l i z e ( & v N o r m a l i z e L i n e D i r , & D 3 D X V E C T O R 3 ( p i p e L i n e D i r . x , p i p e L i n e D i r . y , p i p e L i n e D i r . z ) ) ;  
  
 	 	 	 	 i n t   n S e c t i o n   =   0 ;  
 	 	 	 	 i n t   j   =   0 ;  
 	 	 	 	 f o r   ( i n t   k   =   0 ; k < = n S t a c k ; k + + )  
 	 	 	 	 {  
 	 	 	 	 	 f l o a t   f M o d i f y   =   0 . 0 ;  
 	 	 	 	 	 / / � � � � � � � � � � � � � � � �  
 	 	 	 	 	 i f   ( k   = =   0   )  
 	 	 	 	 	 	 f M o d i f y   =   _ c u t L e n ;  
 	 	 	 	 	 i f   ( k   = =   n S t a c k )  
 	 	 	 	 	 	 f M o d i f y   =   - _ c u t L e n ;  
  
 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 	 o s g : : V e c 3 d   c e n t e r S e c ;  
 	 	 	 	 	 c e n t e r S e c . x ( )   =   s t a r t C a r t . x ( )   +   p i p e L i n e D i r . x ( ) / n S t a c k * k   +   v N o r m a l i z e L i n e D i r . x ( ) * f M o d i f y ;  
 	 	 	 	 	 c e n t e r S e c . y ( )   =   s t a r t C a r t . y ( )   +   p i p e L i n e D i r . y ( ) / n S t a c k * k   +   v N o r m a l i z e L i n e D i r . y ( ) * f M o d i f y ;  
 	 	 	 	 	 c e n t e r S e c . z ( )   =   s t a r t C a r t . z ( )   +   p i p e L i n e D i r . z ( ) / n S t a c k * k   +   v N o r m a l i z e L i n e D i r . z ( ) * f M o d i f y ;  
  
 	 	 	 	 	 d b T r a n s X   =   c e n t e r S e c . x ( )   -   c e n t e r P o s D K E . x ( )     ;  
 	 	 	 	 	 d b T r a n s Y   =   c e n t e r S e c . y ( )   -   c e n t e r P o s D K E . y ( )   ;  
 	 	 	 	 	 d b T r a n s Z   =   c e n t e r S e c . z ( )   -   c e n t e r P o s D K E . z ( ) ;  
  
 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 	 / / D 3 D X M a t r i x T r a n s l a t i o n ( & T r a n s l a t e M a t r i x , d b T r a n s X , d b T r a n s Y , d b T r a n s Z ) ;  
 	 	 	 	 	 T r a n s l a t e M a t r i x . s e t T r a n s ( o s g : : V e c 3 d ( d b T r a n s X , d b T r a n s Y , d b T r a n s Z ) ) ;  
 	 	 	 	 	 r e s u l t M a t r i x   =   r o t a t e M a t r i x   *   T r a n s l a t e M a t r i x ;  
  
 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 	 f o r   ( i n t   i = 0 ; i < v S e c t i o n V t . s i z e ( ) ; i + + )  
 	 	 	 	 	 {  
 	 	 	 	 	 	  
 	 	 	 	 	 	 o s g : : V e c 3   v e c = v S e c t i o n V t [ i ] ;  
  
 	 	 	 	 	 	 / * v e c . x   =   v S e c t i o n V t - > a s A r r a y ( ) [ i ] . x  
 	 	 	 	 	 	 v e c . y   =   v S e c t i o n V t [ i ] . y ;  
 	 	 	 	 	 	 v e c . z   =   v S e c t i o n V t [ i ] . z ; * /  
 	 	 	 	 	 	 i f ( e S h a p e = = e R e c t )  
 	 	 	 	 	 	 	 v P i p e V e r t i c e s - > p u s h _ b a c k ( v e c * r e s u l t M a t r i x ) ;  
  
 	 	 	 	 	 	 v P i p e V e r t i c e s - > p u s h _ b a c k ( v e c * r e s u l t M a t r i x ) ;  
 	 	 	 	 	 	 / / D 3 D X V e c 3 T r a n s f o r m C o o r d ( & v P i p e V e r t i c e s [ j ] , & v e c , & r e s u l t M a t r i x ) ;  
 	 	 	 	 	 	 / / j + + ;  
 	 	 	 	 	 }  
 	 	 	 	 }  
 	 	 	 }  
  
 / / ub�e�{�{�k!j�W�8h�_�Nx 
 	 	 	 o s g : : D r a w a b l e *   b u i l d R e c t P i p e L i n e M o d e l ( i n t   n S l i c e N u m )  
 	 	 	 {  
  
 	 	 	 	 i n t   n S l i c e   =   n S l i c e N u m ;  
 	 	 	 	 i n t   n S t a c k   =   1 ;  
 	 	 	 	 / / e n u m C r o s s S e c t i o n T y p e   e S h a p e   =   m _ B u i l d P i p e L i n e P a r a . _ e P i p e L i n e S h a p e ;  
 	 	 	 	 / / C P o i n t 3 D   c e n t e r P o s D K E   =   m _ B u i l d P i p e L i n e P a r a . _ c e n t e r P o s D K E ;  
 	 	 	 	 / / P i p e S i z e   s i z e   =   m _ B u i l d P i p e L i n e P a r a . _ s i z e ;  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � ? x z � � � � � � � � )  
 	 	 	 	 s t d : : v e c t o r < o s g : : V e c 3 >   v S e c t i o n V e r t i c e s ;  
 / / ���{*j*bb�v��p 
 	 	 	 	 c a l c u S e c t i o n V e r t i c e s ( v S e c t i o n V e r t i c e s , n S l i c e , e R e c t , _ s i z e ) ;  
  
 	 	 	 	 / / 9hnc*j*bb�v��p�S*j*bb�*Npe���{@b	gv��p
 	 	 	 	 o s g : : V e c 3 A r r a y *   v T e m p P i p e V e r t i c e s = n e w   o s g : : V e c 3 A r r a y ; / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 / / v T e m p P i p e V e r t i c e s . r e s i z e ( v S e c t i o n V e r t i c e s . s i z e ( ) * ( n S t a c k + 1 ) ) ;  
 	 	 	 	 / / c a l c u V e r t e x ( v T e m p P i p e V e r t i c e s , n S t a c k , c e n t e r P o s D K E , e S h a p e , v S e c t i o n V e r t i c e s , m _ S t a r t E n d P o i n t D K E ) ;  
 	 	 	 	 c a l c u V e r t e x ( v T e m p P i p e V e r t i c e s , n S t a c k , _ c e n t e r C a r t , e R e c t , v S e c t i o n V e r t i c e s , _ o p t i o n s - > _ s t a r t C a r t , _ o p t i o n s - > _ e n d C a r t ) ;  
  
  
 	 	 	 	 / / ���{v��p�lTϑ 
 	 	 	 	 o s g : : r e f _ p t r < o s g : : V e c 3 A r r a y >   n o r m a l s   =   n e w   o s g : : V e c 3 A r r a y   ;  
 	 	 	 	 n o r m a l s - > r e s i z e ( v T e m p P i p e V e r t i c e s - > s i z e ( ) ) ;  
 	 	 	 	 c o m p u t e r R e c t P i p e L i n e N o r m a l ( v T e m p P i p e V e r t i c e s , n o r m a l s , n S t a c k , n S l i c e N u m ) ;  
  
  
 / / ���{v��p"}_ 
 	 	 	 	 o s g : : D r a w E l e m e n t s U I n t *   t r i a n g l e = n e w   o s g : : D r a w E l e m e n t s U I n t ( o s g : : P r i m i t i v e S e t : : T R I A N G L E S , 0 ) ;  
 	 	 	 	 c a l c u R e c t P i p e L i n e I n d e x ( t r i a n g l e , n S t a c k , n S l i c e N u m ) ;  
  
 / / ub(u�N�~6R�{�k�vo s g : : G e o m e t r y  
 	 	 	 	 	 o s g : : r e f _ p t r < o s g : : G e o m e t r y >   p i p e L i n e = n e w   o s g : : G e o m e t r y ;  
  
 / / \v��p�T�l�~0��r�0v��p"}_�ReQ0Ro s g : : G e o m e t r y -N 
 	 	 	 	 i f ( v T e m p P i p e V e r t i c e s - > s i z e ( ) )  
 	 	 	 	 	 p i p e L i n e - > s e t V e r t e x A r r a y ( v T e m p P i p e V e r t i c e s ) ;  
  
  
 	 	 	 	 i f ( n o r m a l s - > s i z e ( ) )  
 	 	 	 	 	 p i p e L i n e - > s e t N o r m a l A r r a y ( n o r m a l s ,   o s g : : A r r a y : : B I N D _ P E R _ V E R T E X ) ;  
  
  
 	 	 	 	 o s g : : V e c 4 d A r r a y *   c o l o r s = n e w   o s g : : V e c 4 d A r r a y ; / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 c o l o r s - > p u s h _ b a c k ( _ c o l o r ) ;  
 	 	 	 	 p i p e L i n e - > s e t C o l o r A r r a y ( c o l o r s , o s g : : A r r a y : : B I N D _ O V E R A L L ) ;  
 	 	 	  
  
  
  
                                 p i p e L i n e - > a d d P r i m i t i v e S e t ( t r i a n g l e ) ;  
  
 	 	 	 	 r e t u r n   p i p e L i n e . r e l e a s e ( ) ;  
  
  
 	 	 	 }  
  
 / / ���{�e�{v��p"}_��v�c�b�vG e o g l o b e �v�Nx 
 	 	 	 v o i d   c a l c u R e c t P i p e L i n e I n d e x ( o s g : : D r a w E l e m e n t s U I n t *   v D r a w I n d e x , i n t   n S t a c k , i n t   n S l i c e )  
 	 	 	 {  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 f o r   ( i n t   k = 0 ; k < n S t a c k ; k + + )  
 	 	 	 	 {  
 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 	 i n t   n B e g i n I n d e x   =   2 * k * n S l i c e ;  
 	 	 	 	 	 f o r   ( i n t   i = 0 ; i < 2 * ( n S l i c e - 1 ) ; i + = 2 )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i ) ;  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + 2 * n S l i c e ) ;  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + 3 ) ;  
  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + 3 ) ;  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + 2 * n S l i c e ) ;  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + 2 * n S l i c e + 3 ) ;  
 	 	 	 	 	 }  
  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + 2 * n S l i c e - 2 ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + 4 * n S l i c e - 2 ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + 1 ) ;  
  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + 1 ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + 4 * n S l i c e - 2 ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + 2 * n S l i c e + 1 ) ;  
 	 	 	 	 }  
  
 	 	 	 }  
  
 	 	 	 v o i d   c o m p u t e r R e c t P i p e L i n e N o r m a l ( o s g : : V e c 3 A r r a y *   v P i p e L i n e V e r t i c e s , o s g : : V e c 3 A r r a y *   v V e r t i c e N o r m a l s , i n t   n S t a c k , i n t   n S l i c e s )  
 	 	 	 {  
  
 	 	 	 	 o s g : : V e c 3   N o r , p V 1 , p V 2 ;  
 	 	 	 	 f o r   ( i n t   i = 0 ; i < 2 * n S l i c e s - 1 ; i + = 2 )  
 	 	 	 	 {  
 	 	 	 	 	 p V 1   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i + 2 ] ;  
 	 	 	 	 	 p V 2   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i + 2 * n S l i c e s ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i ] ;  
  
 	 	 	 	 	 N o r = p V 1 ^ p V 2 ;  
 	 	 	 	 	 N o r . n o r m a l i z e ( ) ;  
 	 	 	 	 	 / / v F a c e N o r m a l . p u s h _ b a c k ( p N o r m a l ) ;  
  
 	 	 	 	 	 v V e r t i c e N o r m a l s - > a s V e c t o r ( ) [ i ] = N o r ;  
 	 	 	 	 	 v V e r t i c e N o r m a l s - > a s V e c t o r ( ) [ i + 2 * n S l i c e s ] = N o r ;  
 	 	 	 	 	 / / v P i p e L i n e V e r t i c s [ i + 2 * n S l i c e s ] . N o r m a l V a l u e ( N o r m a l i z e N o r ) ;  
 	 	 	 	 }  
  
 	 	 	 	 f o r   ( i n t   i = 1 ; i < 2 * n S l i c e s - 1 ; i + = 2 )  
 	 	 	 	 {  
 	 	 	 	 	 p V 1   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i + 2 ] ;  
 	 	 	 	 	 p V 2   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i + 2 * n S l i c e s ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i ] ;  
 	 	 	 	 	 N o r = p V 1 ^ p V 2 ;  
 	 	 	 	 	 N o r . n o r m a l i z e ( ) ;  
  
 	 	 	 	 	 v V e r t i c e N o r m a l s - > a s V e c t o r ( ) [ i + 2 ] = N o r ;  
 	 	 	 	 	 v V e r t i c e N o r m a l s - > a s V e c t o r ( ) [ i + 2 * n S l i c e s + 2 ] = N o r ;  
 	 	 	 / * 	 	 v P i p e L i n e V e r t i c s [ i + 2 ] . N o r m a l V a l u e ( N o r m a l i z e N o r ) ;  
 	 	 	 	 	 v P i p e L i n e V e r t i c s [ i + 2 * n S l i c e s + 2 ] . N o r m a l V a l u e ( N o r m a l i z e N o r ) ; * /  
 	 	 	 	 }  
  
 	 	 	 	 / / p V 1   =   v P i p e L i n e V e r t i c s [ 2 * n S l i c e s - 1 ] . P o i n t V a l u e ( )   -   v P i p e L i n e V e r t i c s [ 1 ] . P o i n t V a l u e ( ) ;  
 	 	 	 	 / / p V 2   =   v P i p e L i n e V e r t i c s [ 4 * n S l i c e s - 1 ] . P o i n t V a l u e ( )   -   v P i p e L i n e V e r t i c s [ 2 * n S l i c e s - 1 ] . P o i n t V a l u e ( ) ;  
 	 	 	 	 / / D 3 D X V e c 3 C r o s s ( & N o r , & p V 1 , & p V 2 ) ;  
 	 	 	 	 / / D 3 D X V e c 3 N o r m a l i z e ( & N o r m a l i z e N o r , & N o r ) ;  
 	 	 	 	 / / v P i p e L i n e V e r t i c s [ 1 ] . N o r m a l V a l u e ( N o r m a l i z e N o r ) ;  
 	 	 	 	 / / v P i p e L i n e V e r t i c s [ 1 + 2 * n S l i c e s ] . N o r m a l V a l u e ( N o r m a l i z e N o r ) ;  
  
 	 	 	 	 / / v e c t o r < o s g : : V e c 3 d >   v F a c e N o r m a l ;  
 	 	 	 	 / / / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 / / o s g : : V e c 3 d   p N o r m a l , p V 1 , p V 2 ;  
 	 	 	 	 / / f o r   ( i n t   i = 0 ; i < n S l i c e s - 1 ; i + + )  
 	 	 	 	 / / {  
 	 	 	 	 / / 	 p V 1   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i + 1 ] ;  
 	 	 	 	 / / 	 p V 2   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i + n S l i c e s ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i ] ;  
 	 	 	 	 / / 	 p N o r m a l = p V 1 ^ p V 2 ;  
  
 	 	 	 	 / / 	 v F a c e N o r m a l . p u s h _ b a c k ( p N o r m a l ) ;  
 	 	 	 	 / / }  
  
 	 	 	 	 / / / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � ? 
 	 	 	 	 / / i n t   j   =   n S l i c e s ;  
 	 	 	 	 / / p V 1   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ 0 ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ n S l i c e s - 1 ] ;  
 	 	 	 	 / / p V 2   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ n S l i c e s - 1 ] -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ 2 * n S l i c e s - 1 ] ;  
 	 	 	 	 / / p N o r m a l = p V 1 ^ p V 2 ;  
 	 	 	 	 / / / / D 3 D X V e c 3 C r o s s ( & p N o r m a l , & p V 1 , & p V 2 ) ;  
 	 	 	 	 / / v F a c e N o r m a l . p u s h _ b a c k ( p N o r m a l ) ;  
  
 	 	 	 	 / / / / � � � � � � � � � � � � � � � � � � � � ? 
 	 	 	 	 / / o s g : : V e c 3 d   p o i n t N o r m a l , p o i n t N o r m a l i z e ;  
 	 	 	 	 / / f o r   ( i n t   i = 0 ; i < = n S t a c k ; i + + )  
 	 	 	 	 / / {  
 	 	 	 	 / / 	 i n t   n S t a r t I n d e x   =   i * n S l i c e s ;  
 	 	 	 	 / / 	 p o i n t N o r m a l   =   ( v F a c e N o r m a l [ 0 ] + v F a c e N o r m a l [ v F a c e N o r m a l . s i z e ( ) - 1 ] ) / 2 ;  
 	 	 	 	 / / 	 / / D 3 D X V e c 3 N o r m a l i z e ( & p o i n t N o r m a l i z e , & p o i n t N o r m a l ) ;  
 	 	 	 	 / / 	 p o i n t N o r m a l . n o r m a l i z e ( ) ;  
 	 	 	 	 / / 	 v V e r t i c e N o r m a l s - > p u s h _ b a c k ( p o i n t N o r m a l ) ;  
  
 	 	 	 	 / / 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 / / 	 i n t   n N o r a m l I n d e x   =   0 ;  
 	 	 	 	 / / 	 f o r   ( i n t   j = n S t a r t I n d e x + 1 ; j < n S t a r t I n d e x + n S l i c e s ; j + + )  
 	 	 	 	 / / 	 {  
 	 	 	 	 / / 	 	 p o i n t N o r m a l   =   ( v F a c e N o r m a l [ n N o r a m l I n d e x ] + v F a c e N o r m a l [ n N o r a m l I n d e x + 1 ] ) / 2 ;  
 	 	 	 	 / / 	 	 p o i n t N o r m a l . n o r m a l i z e ( ) ;  
 	 	 	 	 / / 	 	 v V e r t i c e N o r m a l s - > p u s h _ b a c k ( p o i n t N o r m a l ) ;  
 	 	 	 	 / / 	 	 n N o r a m l I n d e x + + ;  
 	 	 	 	 / / 	 }  
 	 	 	 	 / / }  
  
 	 	 	 }  
  
  
 	 	 	 v o i d   c a l c u C i r c l e P i p e L i n e I n d e x ( o s g : : D r a w E l e m e n t s U I n t *   v D r a w I n d e x , i n t   n S t a c k , i n t   n S l i c e )  
 	 	 	 {  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 f o r   ( i n t   k = 0 ; k < n S t a c k ; k + + )  
 	 	 	 	 {  
 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 	 i n t   n B e g i n I n d e x   =   k * n S l i c e ;  
 	 	 	 	 	 f o r   ( i n t   i = 0 ; i < n S l i c e - 1 ; i + + )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i ) ;  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + n S l i c e ) ;  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + 1 ) ;  
  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + 1 ) ;  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + n S l i c e ) ;  
 	 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + i + n S l i c e + 1 ) ;  
 	 	 	 	 	 }  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + n S l i c e - 1 ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + 2 * n S l i c e - 1 ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + 2 * n S l i c e - 1 ) ;  
 	 	 	 	 	 v D r a w I n d e x - > p u s h _ b a c k ( n B e g i n I n d e x + n S l i c e ) ;  
 	 	 	 	 }  
 	 	 	 }  
  
 	 	 	 v o i d   c o m p u t e r C i r c l e P i p e L i n e N o r m a l ( o s g : : V e c 3 A r r a y *   v P i p e L i n e V e r t i c e s , o s g : : V e c 3 A r r a y *   v V e r t i c e N o r m a l s , i n t   n S t a c k , i n t   n S l i c e s )  
 	 	 	 {  
  
  
 	 	 	 	 v e c t o r < o s g : : V e c 3 >   v F a c e N o r m a l ;  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 o s g : : V e c 3   p N o r m a l , p V 1 , p V 2 ;  
 	 	 	 	 f o r   ( i n t   i = 0 ; i < n S l i c e s - 1 ; i + + )  
 	 	 	 	 {  
 	 	 	 	 	 p V 1   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i + 1 ] ;  
 	 	 	 	 	 p V 2   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i + n S l i c e s ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ i ] ;  
 	 	 	 	 	 p N o r m a l = p V 1 ^ p V 2 ;  
 	 	 	 	 	  
 	 	 	 	 	 v F a c e N o r m a l . p u s h _ b a c k ( p N o r m a l ) ;  
 	 	 	 	 }  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � ? 
 	 	 	 	 i n t   j   =   n S l i c e s ;  
 	 	 	 	 p V 1   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ 0 ]   -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ n S l i c e s - 1 ] ;  
 	 	 	 	 p V 2   =   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ n S l i c e s - 1 ] -   v P i p e L i n e V e r t i c e s - > a s V e c t o r ( ) [ 2 * n S l i c e s - 1 ] ;  
 	 	 	 	 p N o r m a l = p V 1 ^ p V 2 ;  
 	 	 	 	 / / D 3 D X V e c 3 C r o s s ( & p N o r m a l , & p V 1 , & p V 2 ) ;  
 	 	 	 	 v F a c e N o r m a l . p u s h _ b a c k ( p N o r m a l ) ;  
  
 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � ? 
 	 	 	 	 o s g : : V e c 3   p o i n t N o r m a l , p o i n t N o r m a l i z e ;  
 	 	 	 	 f o r   ( i n t   i = 0 ; i < = n S t a c k ; i + + )  
 	 	 	 	 {  
 	 	 	 	 	 i n t   n S t a r t I n d e x   =   i * n S l i c e s ;  
 	 	 	 	 	 p o i n t N o r m a l   =   ( v F a c e N o r m a l [ 0 ] + v F a c e N o r m a l [ v F a c e N o r m a l . s i z e ( ) - 1 ] ) / 2 ;  
 	 	 	 	 	 / / D 3 D X V e c 3 N o r m a l i z e ( & p o i n t N o r m a l i z e , & p o i n t N o r m a l ) ;  
 	 	 	 	 	 p o i n t N o r m a l . n o r m a l i z e ( ) ;  
 	 	 	 	 	 v V e r t i c e N o r m a l s - > p u s h _ b a c k ( p o i n t N o r m a l ) ;  
  
 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 	 i n t   n N o r a m l I n d e x   =   0 ;  
 	 	 	 	 	 f o r   ( i n t   j = n S t a r t I n d e x + 1 ; j < n S t a r t I n d e x + n S l i c e s ; j + + )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 p o i n t N o r m a l   =   ( v F a c e N o r m a l [ n N o r a m l I n d e x ] + v F a c e N o r m a l [ n N o r a m l I n d e x + 1 ] ) / 2 ;  
 	 	 	 	 	 	 p o i n t N o r m a l . n o r m a l i z e ( ) ;  
 	 	 	 	 	 	 v V e r t i c e N o r m a l s - > p u s h _ b a c k ( p o i n t N o r m a l ) ;  
 	 	 	 	 	 	 n N o r a m l I n d e x + + ;  
 	 	 	 	 	 }  
 	 	 	 	 }  
  
 	 	 	 }  
  
 	 	 	 o s g : : D r a w a b l e *   b u i l d C i r c l e P i p e L i n e M o d e l ( i n t   n S l i c e N u m )  
 	 	 	 {  
 	 	 	 	 i n t   n S t a c k = 1 ;  
 	 	 	 	 s t d : : v e c t o r < o s g : : V e c 3 >   v S e c t i o n V e r t i c e s ;  
 	 	 	 	 c a l c u S e c t i o n V e r t i c e s ( v S e c t i o n V e r t i c e s , n S l i c e N u m , e C i r c l e , _ s i z e ) ;  
  
 	 	 	 	 o s g : : V e c 3 A r r a y *   v T e m p P i p e V e r t i c e s = n e w   o s g : : V e c 3 A r r a y ; / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 / / v T e m p P i p e V e r t i c e s - > r e s i z e ( v S e c t i o n V e r t i c e s . s i z e ( ) * ( n S t a c k + 1 ) ) ;  
 	 	 	 	 c a l c u V e r t e x ( v T e m p P i p e V e r t i c e s , n S t a c k , _ c e n t e r C a r t , e C i r c l e , v S e c t i o n V e r t i c e s , _ o p t i o n s - > _ s t a r t C a r t , _ o p t i o n s - > _ e n d C a r t ) ;  
  
  
 	 	 	 	 o s g : : r e f _ p t r < o s g : : V e c 3 A r r a y >   n o r m a l s   =   n e w   o s g : : V e c 3 A r r a y   ;  
 	 	 	 	 c o m p u t e r C i r c l e P i p e L i n e N o r m a l ( v T e m p P i p e V e r t i c e s , n o r m a l s , n S t a c k , n S l i c e N u m ) ;  
  
  
  
 	 	 	 	 o s g : : D r a w E l e m e n t s U I n t *   t r i a n g l e = n e w   o s g : : D r a w E l e m e n t s U I n t ( o s g : : P r i m i t i v e S e t : : T R I A N G L E S , 0 ) ;  
 	 	 	 	 c a l c u C i r c l e P i p e L i n e I n d e x ( t r i a n g l e , n S t a c k , n S l i c e N u m ) ;  
  
 	 	 	 	 o s g : : r e f _ p t r < o s g : : G e o m e t r y >   p i p e L i n e = n e w   o s g : : G e o m e t r y ;  
  
 	 	 	 	 i f ( v T e m p P i p e V e r t i c e s - > s i z e ( ) )  
 	 	 	 	 	 p i p e L i n e - > s e t V e r t e x A r r a y ( v T e m p P i p e V e r t i c e s ) ;  
 	 / * 	 	 	 i f (   n o r m a l s - > s i z e ( ) )  
 	 	 	 	 	 p i p e L i n e - > s e t V e r t e x A r r a y (   n o r m a l s ) ; * /  
  
 	 	 	 	 i f ( n o r m a l s - > s i z e ( ) )  
 	 	 	 	 	 p i p e L i n e - > s e t N o r m a l A r r a y ( n o r m a l s ,   o s g : : A r r a y : : B I N D _ P E R _ V E R T E X ) ;  
  
  
 	 	 	 	 / / p i p e L i n e - > s e t C o l o r B i n d i n g ( )  
 	 	 	 	 o s g : : V e c 4 d A r r a y *   c o l o r s = n e w   o s g : : V e c 4 d A r r a y ; / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
 	 	 	 	 c o l o r s - > p u s h _ b a c k ( _ c o l o r ) ;  
 	 	 	 	 p i p e L i n e - > s e t C o l o r A r r a y ( c o l o r s , o s g : : A r r a y : : B I N D _ O V E R A L L ) ;  
 	 	 	  
  
  
  
                                 p i p e L i n e - > a d d P r i m i t i v e S e t ( t r i a n g l e ) ;  
  
 	 	 	 	 r e t u r n   p i p e L i n e . r e l e a s e ( ) ;  
 	 	 	 }  
  
 	 	 	 o s g : : N o d e *   b u i l d L o d P i p e L i n e M o d e l ( i n t   l o d )  
 	 	 	 {  
 	 	 	 	 / / R e s e t ( ) ;  
 	 	 	 	 / / v e c t o r < _ 3 D S u r f a c e P a i r >   L i s t T r i a n g l e M e s h P a i r ;  
 	 	 	 	 o s g : : r e f _ p t r < o s g : : G e o d e >   g e o d e = n e w     o s g : : G e o d e ;  
 	 	 	  
 	 	 	  
 	 	 	 	 / / o s g : : r e f _ p t r < o s g : : M a t r i x T r a n s f o r m >   g e o d e = n e w     o s g : : G e o d e ;  
  
 	 	 	 	 s w i t c h ( _ o p t i o n s - > _ s e c t i o n T y p e )  
 	 	 	 	 {  
 	 	 	 	 c a s e   e R e c t :  
 	 	 	 	 	 {  
 	 	 	 	 	 	 g e o d e - > a d d D r a w a b l e ( b u i l d R e c t P i p e L i n e M o d e l ( 4 ) ) ;  
 	 	 	 	 	 	 / / C 3 D T r i a n g l e M e s h *   p T r i a n g l e M e s h 0   =   T o T r i a n g l e M e s h ( & m _ v e c L o d V e r t i c e s [ 0 ] [ 0 ] , m _ v e c L o d V e r t i c e s [ 0 ] . s i z e ( ) , 0 / * � � � � � � � � � � � � � � � � � � � � * / ,  
 	 	 	 	 	 	 / / 	 V E R T E X T Y P E _ V 3 f N 3 f , & m _ v e c L o d I n d i e c s [ 0 ] [ 0 ] , m _ v e c L o d I n d i e c s [ 0 ] . s i z e ( ) , m _ n M a t I D ) ;  
 	 	 	 	 	 	 / / L i s t T r i a n g l e M e s h P a i r . p u s h _ b a c k ( _ 3 D S u r f a c e P a i r ( 0 , p T r i a n g l e M e s h 0 ) ) ;  
 	 	 	 	 	 }  
 	 	 	 	 	 b r e a k ;  
 	 	 	 	 c a s e   e C i r c l e :  
 	 	 	 	 	 {  
 	 	 	 	 	 	 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � l o d  
 	 	 	 	 	 	 / / l o d   = 1    
 	 	 	 	 	 	  
 	 	 	 	 	 	 g e o d e - > a d d D r a w a b l e ( b u i l d C i r c l e P i p e L i n e M o d e l ( 4 * l o d ) ) ;  
 	 	 	 	 	 	 / / C 3 D T r i a n g l e M e s h *   p T r i a n g l e M e s h 0   =   T o T r i a n g l e M e s h ( & m _ v e c L o d V e r t i c e s [ 0 ] [ 0 ] , m _ v e c L o d V e r t i c e s [ 0 ] . s i z e ( ) , 0 / * � � � � � � � � � � � � � � � � � � � � * / ,  
 	 	 	 	 	 	 / / 	 V E R T E X T Y P E _ V 3 f N 3 f , & m _ v e c L o d I n d i e c s [ 0 ] [ 0 ] , m _ v e c L o d I n d i e c s [ 0 ] . s i z e ( ) , m _ n M a t I D ) ;  
 	 	 	 	 	 	 / / L i s t T r i a n g l e M e s h P a i r . p u s h _ b a c k ( _ 3 D S u r f a c e P a i r ( 1 , p T r i a n g l e M e s h 0 ) ) ;  
  
 	 	 	 	 	 	 / / / / l o d   = 2    
 	 	 	 	 	 	 / / B u i l d P i p e L i n e M o d e l ( 8 , m _ v e c L o d V e r t i c e s [ 1 ] , m _ v e c L o d I n d i e c s [ 1 ] ) ;  
 	 	 	 	 	 	 / / C 3 D T r i a n g l e M e s h *   p T r i a n g l e M e s h 1   =   T o T r i a n g l e M e s h ( & m _ v e c L o d V e r t i c e s [ 1 ] [ 0 ] , m _ v e c L o d V e r t i c e s [ 1 ] . s i z e ( ) , 0 / * � � � � � � � � � � � � � � � � � � � � * / ,  
 	 	 	 	 	 	 / / 	 V E R T E X T Y P E _ V 3 f N 3 f , & m _ v e c L o d I n d i e c s [ 1 ] [ 0 ] , m _ v e c L o d I n d i e c s [ 1 ] . s i z e ( ) , m _ n M a t I D ) ;  
 	 	 	 	 	 	 / / L i s t T r i a n g l e M e s h P a i r . p u s h _ b a c k ( _ 3 D S u r f a c e P a i r ( 2 , p T r i a n g l e M e s h 1 ) ) ;  
  
 	 	 	 	 	 	 / / / / l o d   = 3  
 	 	 	 	 	 	 / / B u i l d P i p e L i n e M o d e l ( 2 0 , m _ v e c L o d V e r t i c e s [ 2 ] , m _ v e c L o d I n d i e c s [ 2 ] ) ;  
 	 	 	 	 	 	 / / C 3 D T r i a n g l e M e s h *   p T r i a n g l e M e s h 2   =   T o T r i a n g l e M e s h ( & m _ v e c L o d V e r t i c e s [ 2 ] [ 0 ] , m _ v e c L o d V e r t i c e s [ 2 ] . s i z e ( ) , 0 / * � � � � � � � � � � � � � � � � � � � � * / ,  
 	 	 	 	 	 	 / / 	 V E R T E X T Y P E _ V 3 f N 3 f , & m _ v e c L o d I n d i e c s [ 2 ] [ 0 ] , m _ v e c L o d I n d i e c s [ 2 ] . s i z e ( ) , m _ n M a t I D ) ;  
 	 	 	 	 	 	 / / L i s t T r i a n g l e M e s h P a i r . p u s h _ b a c k ( _ 3 D S u r f a c e P a i r ( 3 , p T r i a n g l e M e s h 2 ) ) ;  
 	 	 	 	 	 }  
 	 	 	 	 	 b r e a k ;  
 	 	 	 	 }  
  
 	 	 	 	 r e t u r n   g e o d e . r e l e a s e ( ) ;  
 	 	 	 	 / / m _ s o l i d P i p e M o d e l - > s e t 3 D S u r f a c e L i s t ( L i s t T r i a n g l e M e s h P a i r ) ;  
 	 	 	 	 / / m _ s o l i d P i p e M o d e l - > w r i t e B u f f e r ( L o d M o d e l B u f f e r ) ;  
 	 	 	 }  
  
 	 	 	 s t d : : s t r i n g   c r e a t S y m b o l U R L ( U I N T 6 4   s y m K e y )  
 	 	 	 {  
  
 	 	 	     / / h t t p : / / 1 9 2 . 1 6 8 . 4 2 . 1 4 7 : 9 0 1 0 / P L S / p l s ? S E R V I C E = P L S & V E R S I O N = 1 . 0 . 0 & R E Q U E S T = G e t S y m b o l & L A Y E R = p i p e t e s t & S Y M B O L I D = 4 8 3 4 8 5 8 1 0 6 8 8  
  
 	 	 	 	 s t d : : s t r i n g   t i l e U r l = _ o p t i o n s - > _ s e r v i c e U r l ;  
  
 	 	 	 	 s t d : : s t r i n g s t r e a m   b u f ;  
  
  
 	 	 	 	 b u f < < t i l e U r l < < " ? S E R V I C E = P L S & V E R S I O N = 1 . 0 . 0 & R E Q U E S T = G e t S y m b o l & L A Y E R = " < < _ o p t i o n s - > _ l a y e r N a m e < < " & S Y M B O L I D = " < < _ o p t i o n s - > _ m o d e l G e o m e t r y I D ;  
  
  
 	 	 	 	 / * b u f < < " / D a t a S e r v e r ? l = " < < k e y _ L < < " & x = " < < k e y _ Y < < " & y = " < < k e y _ X ; * /  
 	 	 	 	 / / b u f < < " / G e t T i l e ? l = " < < l e v e l < < " & x = " < < c o l < < " & y = " < < r o w ;  
 	 	 	 	 / * b u f < < " / D a t a S e r v e r ? l = " < < 1 7 < < " & x = " < < 1 0 4 3 0 7 < < " & y = " < < 2 3 0 2 7 ; * /  
 	 	 	 	 / / t i l e U r l + = b u f . s t r ( ) ;  
 	 	 	 	 / * s t r T i l e = " h t t p : / / 1 9 2 . 1 6 8 . 4 2 . 1 7 8 : 9 0 1 0 / Y I N G X I A N G / D a t a S e r v e r ? l = 1 7 & x = 1 0 4 3 0 7 & y = 2 3 0 2 7 " ; * /  
 	 	 	 	 r e t u r n   b u f . s t r ( ) ;  
  
 	 	 	 }  
  
  
 # i f   0  
 	 	 	 v o i d   g e t S y m b o l F r o m L o c a l ( )  
 	 	 	 {  
  
 	 	 	 	 s t d : : m a p < U L O N G L O N G , o s g : : V e c 4 d > : : i t e r a t o r   c o l o r i t r = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . f i n d ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 	 	 	 i f   ( c o l o r i t r ! = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . e n d ( ) )  
 	 	 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 	 	 _ c o l o r = c o l o r i t r - > s e c o n d ;  
 	 	 	 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 	 	 	 }  
  
 	 	 	 	 i n t   s i z e ;  
 	 	 	 	 c h a r *   d a t a ;  
 	 	 	 	 _ o p t i o n s - > _ d a t a B a s e - > _ s y m D B - > Q u e r y S i n g l e K e y V a l u e T a b l e ( " M o d e l S y m b o l " , _ o p t i o n s - > _ m o d e l G e o m e t r y I D , s i z e , & d a t a ) ;  
  
 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 B u f f e r   t e m p B u f ( d a t a + 5 ,   s i z e ) ;  
 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 {  
 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 }  
  
 	 	 	 	 d e l e t e [ ]   d a t a ;  
 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . i n s e r t ( m a k e _ p a i r ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D , _ c o l o r ) ) ;  
 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 }  
  
 	 	 	 v o i d   g e t S y m b o l F r o m S e r v i c e ( )  
 	 	 	 {  
 	 	 	 	 / / c r e a t S y m b o l U R L ( s y m K e y )  
  
 	 	 	 	 s t d : : m a p < U L O N G L O N G , o s g : : V e c 4 d > : : i t e r a t o r   c o l o r i t r = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . f i n d ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 	 	 	 i f   ( c o l o r i t r ! = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . e n d ( ) )  
 	 	 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 	 	 _ c o l o r = c o l o r i t r - > s e c o n d ;  
 	 	 	 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 	 	 	 }  
  
 	 	 	 	 s t d : : s t r i n g   p i p e S y m b o l N a m e = _ o p t i o n s - > c r e a t e M a t e r i a l N a m e ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
  
 	 	 	 	 / / / / s t d : : s t r i n g   t i l e D a t a ;  
 	 	 	 	 c h a r *   d a t a ;  
 	 	 	 	 i n t       d a t a L e n ;  
 	 	 	 	 i f ( _ o p t i o n s - > _ c a c h e - > r e a d D a t a F r o m C a c h e ( p i p e S y m b o l N a m e , d a t a L e n , & d a t a ) )  
 	 	 	 	 {  
 	 	 	 	 	 i f   ( d a t a L e n ! = 0 )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 	 	 B u f f e r   t e m p B u f ( d a t a + 2 4 ,   d a t a L e n - 2 4 ) ;  
 	 	 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 	 }  
  
 	 	 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 }  
  
 	 	 	 	 	 d e l e t e   [ ] d a t a ;  
 	 	 	 	 }  
 	 	 	 	 e l s e  
 	 	 	 	 {  
 	 	 	 	 	 s t d : : s t r i n g   S y m b o l U r l = c r e a t S y m b o l U R L ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 D o w n l o a d   d l ;  
 	 	 	 	 	 i f ( ! d l . d o w n l o a d D a t a ( S y m b o l U r l ) )  
 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 / / 	 / /       s t d : : s t r i n g 	 t i l e D a t a = o s g E a r t h : : U R I ( t i l e U r l . c _ s t r ( ) ) . g e t S t r i n g ( ) ;  
  
  
 	 	 	 	 	 i f   ( d l . s i z e ! = 0 )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 _ o p t i o n s - > _ c a c h e - > w r i t e D a t a T o C a c h e ( p i p e S y m b o l N a m e , d l . s i z e , c o n s t _ c a s t < c h a r   * > ( d l . d a t a ) ) ;  
 	 	 	 	 	 }  
  
  
 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 	 B u f f e r   t e m p B u f ( c o n s t _ c a s t < c h a r   * > ( d l . d a t a + 2 4 ) ,   d l . s i z e - 2 4 ) ;  
  
  
 	 / * 	 	 	 	 f o r   ( i n t   i = 0 ; i < 1 0 0 ; i + + )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 t e m p B u f . s e t P o s ( i ) ;  
 	 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
 	 	 	 	 	 	 i f   ( p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 i n t   a = 0 ;  
 	 	 	 	 	 	 }  
 	 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 } * /  
  
 	 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 }  
  
 	 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . i n s e r t ( m a k e _ p a i r ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D , _ c o l o r ) ) ;  
 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 / / B u f f e r 2 F e a t u r e s ( _ f e a t u r e s , c o n s t _ c a s t < c h a r   * > ( d l . d a t a ) , d l . s i z e ) ;  
 	 	 	 	 	 	 / * 	 C S Q L i t e O P   t i l e D B ;  
 	 	 	 	 	 t i l e D B . O p e n D a t a B a s e ( " C : / U s e r s / A d m i n i s t r a t o r / D e s k t o p / j s / j s . t i l e " ) ;  
  
 	 	 	 	 	 c h a r *   p T i l e B u f f ;  
 	 	 	 	 	 i n t   n S i z e ;  
  
  
 	 	 	 	 	 i f ( t i l e D B . G e t T i l e D a t a B y T i l e K e y ( l e v e l , c o l , r o w , & p T i l e B u f f , n S i z e ) ) * /  
 	 	 	 / * 	 	 f o r ( i n t   i = 0 ; i < 1 0 0 ; i + + )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 c h a r *   a = c o n s t _ c a s t < c h a r   * > ( d l . d a t a + 2 8 + i ) ;  
 	 	 	 	 	 	 i n t   c = 0 ;  
 	 	 	 	 	 } * /  
 	 	 	 	 	  
 	 	 	 	 	 / * 	 	 	 	 i f   ( d l . s i z e > 2 8 )  
 	 	 	 	 	 {  
 	 	 	 	 	 B u f f e r 2 F e a t u r e s ( c o n s t _ c a s t < c h a r   * > ( d l . d a t a + 3 3 ) , d l . s i z e - 3 3 ) ;  
 	 	 	 	 	 } * /  
 	 	 	 	 	  
  
 	 	 	 	 }  
  
 	  
  
 	 	 	 	  
 	 	 	 }  
 # e n d i f  
  
 # i f   0  
 	 	 	 v o i d   g e t S y m b o l F r o m L o c a l ( )  
 	 	 	 	 {  
 	 	 	 	 	 s t d : : s t r i n g   p i p e S y m b o l N a m e = _ o p t i o n s - > c r e a t e M a t e r i a l N a m e ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 / / s t d : : m a p < U L O N G L O N G , o s g : : V e c 4 d > : : i t e r a t o r   c o l o r i t r = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . f i n d ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 / / i f   ( c o l o r i t r ! = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . e n d ( ) )  
 	 	 	 	 	 / / {  
 	 	 	 	 	 / / 	 _ c o l o r = c o l o r i t r - > s e c o n d ;  
 	 	 	 	 	 / / 	 r e t u r n ;  
 	 	 	 	 	 / / }  
  
 	 	 	 	 	 o s g : : r e f _ p t r < o s g : : O b j e c t >   o b j = (   G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ m e m C a c h e - > g e t O b j e c t F r o m C a c h e ( p i p e S y m b o l N a m e ) ) ;  
 	 	 	 	 	 o s g : : r e f _ p t r < o s g : : M a t e r i a l >   m = ( o s g : : M a t e r i a l * ) ( o b j . g e t ( ) ) ;  
  
 	 	 	 	 	 i f   ( ! o b j . v a l i d ( ) )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 i n t   s i z e ;  
 	 	 	 	 	 	 c h a r *   d a t a ;  
 	 	 	 	 	 	 _ o p t i o n s - > _ d a t a B a s e - > _ s y m D B - > Q u e r y S i n g l e K e y V a l u e T a b l e ( " M o d e l S y m b o l " , _ o p t i o n s - > _ m o d e l G e o m e t r y I D , s i z e , & d a t a ) ;  
  
 	 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 	 	 B u f f e r   t e m p B u f ( d a t a + 5 ,   s i z e ) ;  
 	 	 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 	 }  
  
 	 	 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 	 m   =   n e w   o s g : : M a t e r i a l ( ) ;  
 	 	 	 	 	 	 m - > s e t A m b i e n t ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r * 0 . 5 ) ;  
 	 	 	 	 	 	 m - > s e t D i f f u s e ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 	 m - > s e t S p e c u l a r ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 / / 	 	 	 m - > s e t E m i s s i o n ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 	 m - > s e t S h i n i n e s s ( m - > F R O N T _ A N D _ B A C K ,   3 2 . 0 ) ;  
  
  
 	 	 	 	 	 	 G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ m e m C a c h e - > a d d O b j e c t T o C a c h e ( p i p e S y m b o l N a m e , m ) ;  
 	 	 	 	 	 	 / / G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . i n s e r t ( m a k e _ p a i r ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D , _ c o l o r ) ) ;  
 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
  
 	 	 	 	 	 }  
 	 	 	 	 	 e l s e  
 	 	 	 	 	 {  
 	 	 	 	 	 	 i n t   a = 0 ;  
 	 	 	 	 	 }  
  
  
  
 	 	 	 	 	 t h i s - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t A t t r i b u t e A n d M o d e s ( m ,   o s g : : S t a t e A t t r i b u t e : : O N   |   o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D   ) ;  
  
  
  
 	 	 	 	 }  
  
 	 	 	 v o i d   g e t S y m b o l F r o m S e r v i c e ( )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 s t d : : s t r i n g   p i p e S y m b o l N a m e = _ o p t i o n s - > c r e a t e M a t e r i a l N a m e ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 	 / / s t d : : m a p < U L O N G L O N G , o s g : : V e c 4 d > : : i t e r a t o r   c o l o r i t r = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . f i n d ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 	 / / i f   ( c o l o r i t r ! = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . e n d ( ) )  
 	 	 	 	 	 	 / / {  
 	 	 	 	 	 	 / / 	 _ c o l o r = c o l o r i t r - > s e c o n d ;  
 	 	 	 	 	 	 / / 	 r e t u r n ;  
 	 	 	 	 	 	 / / }  
  
 	 	 	 	 	 	 o s g : : r e f _ p t r < o s g : : O b j e c t >   o b j = (   G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ m e m C a c h e - > g e t O b j e c t F r o m C a c h e ( p i p e S y m b o l N a m e ) ) ;  
 	 	 	 	 	 	 o s g : : r e f _ p t r < o s g : : M a t e r i a l >   m = ( o s g : : M a t e r i a l * ) ( o b j . g e t ( ) ) ;  
  
 	 	 	 	 	 	 i f   ( ! o b j . v a l i d ( ) )  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 c h a r *   d a t a ;  
 	 	 	 	 	 	 i n t       d a t a L e n ;  
 	 	 	 	 	 	 i f ( _ o p t i o n s - > _ c a c h e - > r e a d D a t a F r o m C a c h e ( p i p e S y m b o l N a m e , d a t a L e n , & d a t a ) )  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 i f   ( d a t a L e n ! = 0 )  
 	 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 	 	 	 	 B u f f e r   t e m p B u f ( d a t a + 2 4 ,   d a t a L e n - 2 4 ) ;  
 	 	 	 	 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 	 	 	 }  
  
 	 	 	 	 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 	 }  
  
 	 	 	 	 	 	 	 d e l e t e   [ ] d a t a ;  
 	 	 	 	 	 	 }  
 	 	 	 	 	 	 e l s e  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 s t d : : s t r i n g   S y m b o l U r l = c r e a t S y m b o l U R L ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D ) ;  
 	 	 	 	 	 	 	 D o w n l o a d   d l ;  
 	 	 	 	 	 	 	 i f ( ! d l . d o w n l o a d D a t a ( S y m b o l U r l ) )  
 	 	 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 	 	 / / 	 / /       s t d : : s t r i n g 	 t i l e D a t a = o s g E a r t h : : U R I ( t i l e U r l . c _ s t r ( ) ) . g e t S t r i n g ( ) ;  
  
  
 	 	 	 	 	 	 	 i f   ( d l . s i z e ! = 0 )  
 	 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 	 _ o p t i o n s - > _ c a c h e - > w r i t e D a t a T o C a c h e ( p i p e S y m b o l N a m e , d l . s i z e , c o n s t _ c a s t < c h a r   * > ( d l . d a t a ) ) ;  
 	 	 	 	 	 	 	 }  
  
  
 	 	 	 	 	 	 	 C M a t e r i a l *   p M a t e r i a l   =   n e w   C M a t e r i a l ( ) ;  
  
 	 	 	 	 	 	 	 B u f f e r   t e m p B u f ( c o n s t _ c a s t < c h a r   * > ( d l . d a t a + 2 4 ) ,   d l . s i z e - 2 4 ) ;  
  
  
 	 	 	 	 	 	 	 i f   ( ! p M a t e r i a l - > r e a d B u f f e r ( t e m p B u f ) )  
 	 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 	 	 r e t u r n ;  
 	 	 	 	 	 	 	 }  
  
 	 	 	 	 	 	 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 	 	 / / G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . i n s e r t ( m a k e _ p a i r ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D , _ c o l o r ) ) ;  
 	 	 	 	 	 	 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
 	 	 	 	 	 	 }  
  
 	 	 	 	 	 	 / / 	 _ c o l o r = t o C o l o r ( p M a t e r i a l - > g e t S i m p l e M a t ( ) . u l C o l o r ) ;  
 	 	 	 	 	 	 	 m   =   n e w   o s g : : M a t e r i a l ( ) ;  
 	 	 	 	 	 	 	 m - > s e t A m b i e n t ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r * 0 . 5 ) ;  
 	 	 	 	 	 	 	 m - > s e t D i f f u s e ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 	 	 m - > s e t S p e c u l a r ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 	 	 / / 	 	 	 m - > s e t E m i s s i o n ( m - > F R O N T _ A N D _ B A C K ,   _ c o l o r ) ;  
 	 	 	 	 	 	 	 m - > s e t S h i n i n e s s ( m - > F R O N T _ A N D _ B A C K ,   3 2 . 0 ) ;  
  
  
 	 	 	 	 	 	 	 G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ m e m C a c h e - > a d d O b j e c t T o C a c h e ( p i p e S y m b o l N a m e , m ) ;  
 	 	 	 	 	 	 	 / / G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ c o l o r M a p . i n s e r t ( m a k e _ p a i r ( _ o p t i o n s - > _ m o d e l G e o m e t r y I D , _ c o l o r ) ) ;  
 	 	 	 	 	 	 / / 	 S a f e D e l e t e ( p M a t e r i a l ) ;  
  
 	 	 	 	 	 	 }  
 	 	 	 / * 	 	 	 e l s e  
 	 	 	 	 	 	 {  
 	 	 	 	 	 	 	 i n t   a = 0 ;  
 	 	 	 	 	 	 } * /  
  
  
  
 	 	 	 	 	 	 t h i s - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t A t t r i b u t e A n d M o d e s ( m ,   o s g : : S t a t e A t t r i b u t e : : O N   |   o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D   ) ;  
  
  
  
 	 	 	 	 	 }  
 # e n d i f  
 	 	 	 v o i d   b u i l d P i p e L i n e M o d e l ( )  
 	 	 	 {  
  
 	 	 	 	 / / h t t p : / / 1 9 2 . 1 6 8 . 4 2 . 1 4 7 : 9 0 1 0 / P L S / p l s ? S E R V I C E = P L S & V E R S I O N = 1 . 0 . 0 & R E Q U E S T = G e t S y m b o l & L A Y E R = p i p e t e s t & S Y M B O L I D = 4 8 3 4 8 5 8 1 0 6 8 8  
  
 	 	 	 	 i f   ( _ o p t i o n s - > _ s e r v i c e U r l = = " " )  
 	 	 	 	 {  
 	 	 	 	 	 g e t S y m b o l F r o m L o c a l ( ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e  
 	 	 	 	 {  
 	 	 	 	 	 g e t S y m b o l F r o m S e r v i c e ( ) ;  
 	 	 	 	 }  
  
                                 / / s e t C e n t e r ( ) ;  
  
 	 	 	 	 i f ( _ o p t i o n s - > _ s e c t i o n T y p e = = e C i r c l e )  
 	 	 	 	 {  
 	 	 	 	 o s g : : r e f _ p t r < o s g : : M a t r i x T r a n s f o r m >   m t 1   =   n e w   o s g : : M a t r i x T r a n s f o r m ( ) ;  
 	 	 	 	 m t 1 - > s e t M a t r i x ( / * o s g : : M a t r i x d : : s c a l e ( 1 0 0 0 0 0 0 0 , 1 0 0 0 0 0 0 0 , 1 0 0 0 0 0 0 0 ) * * / o s g : : M a t r i x d : : t r a n s l a t e ( _ c e n t e r C a r t ) ) ;  
 	 	 	 	 m t 1 - > a d d C h i l d ( b u i l d L o d P i p e L i n e M o d e l ( 1 ) ) ;  
 / / 	 	 	 	 m t 1 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ D E P T H _ T E S T ,   o s g : : S t a t e A t t r i b u t e : : O N | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
 / / 	 	 	 	 m t 1 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ C U L L _ F A C E ,   o s g : : S t a t e A t t r i b u t e : : O F F | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
  
 	 	 	 	 o s g : : r e f _ p t r < o s g : : M a t r i x T r a n s f o r m >   m t 2   =   n e w   o s g : : M a t r i x T r a n s f o r m ( ) ;  
 	 	 	 	 m t 2 - > s e t M a t r i x ( / * o s g : : M a t r i x d : : s c a l e ( 1 0 0 0 0 0 0 0 , 1 0 0 0 0 0 0 0 , 1 0 0 0 0 0 0 0 ) * * / o s g : : M a t r i x d : : t r a n s l a t e ( _ c e n t e r C a r t ) ) ;  
 	 	 	 	 m t 2 - > a d d C h i l d ( b u i l d L o d P i p e L i n e M o d e l ( 2 ) ) ;  
 / / 	 	 	 	 m t 2 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ D E P T H _ T E S T ,   o s g : : S t a t e A t t r i b u t e : : O N | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
 / / 	 	 	 	 m t 2 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ C U L L _ F A C E ,   o s g : : S t a t e A t t r i b u t e : : O F F | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
  
 	 	 	 	 o s g : : r e f _ p t r < o s g : : M a t r i x T r a n s f o r m >   m t 3   =   n e w   o s g : : M a t r i x T r a n s f o r m ( ) ;  
 	 	 	 	 m t 3 - > s e t M a t r i x ( / * o s g : : M a t r i x d : : s c a l e ( 1 0 0 0 0 0 0 0 , 1 0 0 0 0 0 0 0 , 1 0 0 0 0 0 0 0 ) * * / o s g : : M a t r i x d : : t r a n s l a t e ( _ c e n t e r C a r t ) ) ;  
 	 	 	 	 m t 3 - > a d d C h i l d ( b u i l d L o d P i p e L i n e M o d e l ( 3 ) ) ;  
 / / 	 	 	 	 m t 3 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ D E P T H _ T E S T ,   o s g : : S t a t e A t t r i b u t e : : O N | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
 / / 	 	 	 	 m t 3 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ C U L L _ F A C E ,   o s g : : S t a t e A t t r i b u t e : : O F F | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
 	 	 	 	 / / m t - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ C U L L _ F A C E ,   o s g : : S t a t e A t t r i b u t e : : O F F ) ;  
 	 	 	 	 / / / / m t - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ D E P T H _ T E S T ,   o s g : : S t a t e A t t r i b u t e : : O F F ) ;  
 	 	 	 	 / / m t - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ L I G H T I N G ,   o s g : : S t a t e A t t r i b u t e : : O F F ) ;  
 	 	 	 	  
 	 	 	 	 / / o s g : : L O D *   l o d P i p e L i n e = n e w   o s g : : L O D ;  
 	 	 	 	  
 	 	 	 	 a d d C h i l d ( m t 1 , 2 0 0 , F L T _ M A X ) ;  
 	 	 	 	 a d d C h i l d ( m t 2 , 4 0 , 2 0 0 ) ;  
 	 	 	 	 a d d C h i l d ( m t 3 , 0 , 4 0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e  
 	 	 	 	 {  
 	 	 	 	 	 o s g : : r e f _ p t r < o s g : : M a t r i x T r a n s f o r m >   m t 1   =   n e w   o s g : : M a t r i x T r a n s f o r m ( ) ;  
 	 	 	 	 	 m t 1 - > s e t M a t r i x ( / * o s g : : M a t r i x d : : s c a l e ( 1 0 0 0 0 0 0 0 , 1 0 0 0 0 0 0 0 , 1 0 0 0 0 0 0 0 ) * * / o s g : : M a t r i x d : : t r a n s l a t e ( _ c e n t e r C a r t ) ) ;  
 	 	 	 	 	 m t 1 - > a d d C h i l d ( b u i l d L o d P i p e L i n e M o d e l ( 1 ) ) ;  
 / / 	 	 	 	 	 m t 1 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ D E P T H _ T E S T ,   o s g : : S t a t e A t t r i b u t e : : O N | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
 / / 	 	 	 	 	 m t 1 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ C U L L _ F A C E ,   o s g : : S t a t e A t t r i b u t e : : O F F | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
 	 	 	 	 	 a d d C h i l d ( m t 1 , 0 , F L T _ M A X ) ;  
 	 	 	 	 }  
  
 	 / * 	 	 	 G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ i m a g e L a y e r A l p h a = 0 . 6 ;  
 	 	 	 	 f l o a t   a = G e o G l o b e : : T o o l : : G l o b a l S e t t i n g : : i n s t a n c e ( ) - > _ i m a g e L a y e r A l p h a ; * /  
 	 	 	 	 / / Q u e r y S i n g l e K e y V a l u e T a b l e ( " M o d e l G e o m e t r y " , g e o K e y , d a t a L e n , g e o D a t a )  
 	 	 	  
  
 / / 	 	 	 	 o s g : : M a t e r i a l *   m   =   n e w   o s g : : M a t e r i a l ( ) ;  
 / / 	 	 	 	 m - > s e t A m b i e n t ( m - > F R O N T _ A N D _ B A C K ,   o s g : : V e c 4 ( 1 , 1 , 0 , 1 ) ) ;  
 / / 	 	 	         m - > s e t D i f f u s e ( m - > F R O N T _ A N D _ B A C K ,   o s g : : V e c 4 ( 1 , 1 , 0 , 1 ) ) ;  
 / / 	 	 	         m - > s e t S p e c u l a r ( m - > F R O N T _ A N D _ B A C K ,   o s g : : V e c 4 ( 1 , 1 , 0 , 1 ) ) ;  
 / / 	 	 	 	 m - > s e t E m i s s i o n ( m - > F R O N T _ A N D _ B A C K ,   o s g : : V e c 4 ( 1 , 1 , 0 , 1 ) ) ;  
 / / 	 	 	 	 m - > s e t S h i n i n e s s ( m - > F R O N T _ A N D _ B A C K ,   3 2 . 0 ) ;  
 / / 	 	 	 	 t h i s - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t A t t r i b u t e A n d M o d e s ( m ,   o s g : : S t a t e A t t r i b u t e : : O N   |   o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D   ) ;  
 	 	 	 	 t h i s - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ L I G H T I N G , o s g : : S t a t e A t t r i b u t e : : O N | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
 	 	 	 	 / / 	 	 	 	 	 m t 1 - > g e t O r C r e a t e S t a t e S e t ( ) - > s e t M o d e ( G L _ C U L L _ F A C E ,   o s g : : S t a t e A t t r i b u t e : : O F F | o s g : : S t a t e A t t r i b u t e : : P R O T E C T E D ) ;  
 	 	 	 	  
 	 	 	 	 / / r e t u r n   m t . r e l e a s e ( ) ;  
 	 	 	 }  
  
 	 	 	 o s g : : V e c 4 d     t o C o l o r ( l o n g   l C o l o r )  
 	 	 	 {  
 	 	 	 	 l o n g   a l p h a   =   ( l C o l o r   > >   2 4 )   &   0 x f f ;  
 	 	 	 	 l o n g   R e d       =   ( l C o l o r   > >   1 6 )   &   0 x f f ;  
 	 	 	 	 l o n g   G r e e n   =   ( l C o l o r   > >   8 )     &   0 x f f ;  
 	 	 	 	 l o n g   B l u e     =     l C o l o r 	 	 &   0 x f f ;  
  
 	 	 	 	 r e t u r n     o s g : : V e c 4 d ( R e d / 2 5 5 . 0 , G r e e n / 2 5 5 . 0 , B l u e / 2 5 5 . 0 , a l p h a / 2 5 5 . 0 ) ;  
 	 	 	 }  
  
 	 	 	 v o i d   t r a v e r s e ( N o d e V i s i t o r &   n v )  
 	 	 	 {  
 	 	 	 	 / / r e t u r n ;  
 	 	 	 	 i f   ( n v . g e t T r a v e r s a l M o d e ( )   = =   n v . T R A V E R S E _ A L L _ C H I L D R E N   )  
 	 	 	 	 	 r e t u r n ;  
  
 	 	 	 / * 	 o s g : : N o d e : : P a r e n t L i s t   p l = g e t P a r e n t s ( ) ;  
 	 	 	 	 n v . * /  
 	 	 	 	  
  
 	 	 	 	 / * s t d : : l i s t < s t d : : s t r i n g > : : i t e r a t o r   b e g i n = _ o p t i o n s - > _ s e t t i n g - > _ h e i g h t L i g h t L i s t . b e g i n ( ) ;  
 	 	 	 	 s t d : : l i s t < s t d : : s t r i n g > : : i t e r a t o r   e n d = _ o p t i o n s - > _ s e t t i n g - > _ h e i g h t L i g h t L i s t . e n d ( ) ;  
 	 	 	 	 s t d : : l i s t < s t d : : s t r i n g > : : i t e r a t o r   f i n d = s t d : : f i n d ( b e g i n , e n d , g e t N a m e ( ) ) ;  
 	 	 	 	 i f   ( f i n d ! = e n d )  
 	 	 	 	 {  
 	 	 	 	 	 s e l e c t ( t r u e ) ;  
 	 	 	 	 	 _ o p t i o n s - > _ s e t t i n g - > _ h e i g h t L i g h t L i s t . e r a s e ( f i n d ) ;  
 	 	 	 	 } * /  
  
 	 	 	 / * 	 s t d : : l i s t < s t d : : s t r i n g > : : i t e r a t o r   b e g i n = _ o p t i o n s - > _ s e t t i n g - > _ h e i g h t L i g h t L i s t . b e g i n ( ) ;  
 	 	 	 	 s t d : : l i s t < s t d : : s t r i n g > : : i t e r a t o r   e n d = _ o p t i o n s - > _ s e t t i n g - > _ h e i g h t L i g h t L i s t . e n d ( ) ; * /  
 	 	 	 	 / / s t d : : l i s t < s t d : : s t r i n g > : : i t e r a t o r   f i n d = s t d : : f i n d ( b e g i n , e n d , g e t N a m e ( ) ) ;  
 	 	 	 	 s t d : : m u l t i m a p < s t d : : s t r i n g , b o o l > : : i t e r a t o r   f i n d = _ o p t i o n s - > _ s e t t i n g - > _ h e i g h t L i g h t M a p . f i n d ( g e t N a m e ( ) ) ;  
 	 	 	 	 i f   ( f i n d ! = _ o p t i o n s - > _ s e t t i n g - > _ h e i g h t L i g h t M a p . e n d ( ) )  
 	 	 	 	 {  
 	 	 	 	 	 s e l e c t ( f i n d - > s e c o n d ) ;  
 	 	 	 	 	 _ o p t i o n s - > _ s e t t i n g - > _ h e i g h t L i g h t M a p . e r a s e ( f i n d ) ;  
 	 	 	 	 }  
  
  
 	 	 	 	 s w i t c h ( n v . g e t T r a v e r s a l M o d e ( ) ) 
 	 	 	 	 { 
 	 	 	 	 c a s e ( N o d e V i s i t o r : : T R A V E R S E _ A L L _ C H I L D R E N ) : 
 	 	 	 	 	 s t d : : f o r _ e a c h ( _ c h i l d r e n . b e g i n ( ) , _ c h i l d r e n . e n d ( ) , N o d e A c c e p t O p ( n v ) ) ; 
 	 	 	 	 	 b r e a k ; 
 	 	 	 	 c a s e ( N o d e V i s i t o r : : T R A V E R S E _ A C T I V E _ C H I L D R E N ) : 
 	 	 	 	 	 { 
 	 	 	 	 	 	 f l o a t   r e q u i r e d _ r a n g e   =   0 ; 
 	 	 	 	 	 	 i f   ( _ r a n g e M o d e = = D I S T A N C E _ F R O M _ E Y E _ P O I N T ) 
 	 	 	 	 	 	 { 
 	 	 	 	 	 	 	 r e q u i r e d _ r a n g e   =   n v . g e t D i s t a n c e T o V i e w P o i n t ( g e t C e n t e r ( ) , t r u e ) ; 
 	 	 	 	 	 	 } 
 	 	 	 	 	 	 e l s e 
 	 	 	 	 	 	 { 
 	 	 	 	 	 	 	 o s g : : C u l l S t a c k *   c u l l S t a c k   =   d y n a m i c _ c a s t < o s g : : C u l l S t a c k * > ( & n v ) ; 
 	 	 	 	 	 	 	 i f   ( c u l l S t a c k   & &   c u l l S t a c k - > g e t L O D S c a l e ( ) ) 
 	 	 	 	 	 	 	 { 
 	 	 	 	 	 	 	 	 r e q u i r e d _ r a n g e   =   c u l l S t a c k - > c l a m p e d P i x e l S i z e ( g e t B o u n d ( ) )   /   c u l l S t a c k - > g e t L O D S c a l e ( ) ; 
 	 	 	 	 	 	 	 } 
 	 	 	 	 	 	 	 e l s e 
 	 	 	 	 	 	 	 { 
 	 	 	 	 	 	 	 	 / /   f a l l b a c k   t o   s e l e c t i n g   t h e   h i g h e s t   r e s   t i l e   b y 
 	 	 	 	 	 	 	 	 / /   f i n d i n g   o u t   t h e   m a x   r a n g e 
 	 	 	 	 	 	 	 	 f o r ( u n s i g n e d   i n t   i = 0 ; i < _ r a n g e L i s t . s i z e ( ) ; + + i ) 
 	 	 	 	 	 	 	 	 { 
 	 	 	 	 	 	 	 	 	 r e q u i r e d _ r a n g e   =   o s g : : m a x i m u m ( r e q u i r e d _ r a n g e , _ r a n g e L i s t [ i ] . f i r s t ) ; 
 	 	 	 	 	 	 	 	 } 
 	 	 	 	 	 	 	 } 
 	 	 	 	 	 	 } 
 
 	 	 	 	 	 	 u n s i g n e d   i n t   n u m C h i l d r e n   =   _ c h i l d r e n . s i z e ( ) ; 
 	 	 	 	 	 	 i f   ( _ r a n g e L i s t . s i z e ( ) < n u m C h i l d r e n )   n u m C h i l d r e n = _ r a n g e L i s t . s i z e ( ) ; 
 
 	 	 	 	 	 	 f o r ( u n s i g n e d   i n t   i = 0 ; i < n u m C h i l d r e n ; + + i ) 
 	 	 	 	 	 	 { 
 	 	 	 	 	 	 	 i f   ( _ r a n g e L i s t [ i ] . f i r s t < = r e q u i r e d _ r a n g e   & &   r e q u i r e d _ r a n g e < _ r a n g e L i s t [ i ] . s e c o n d ) 
 	 	 	 	 	 	 	 { 
 	 	 	 	 	 	 	 	 _ c h i l d r e n [ i ] - > a c c e p t ( n v ) ; 
 	 	 	 	 	 	 	 } 
 	 	 	 	 	 	 } 
 	 	 	 	 	 	 b r e a k ; 
 	 	 	 	 	 } 
 	 	 	 	 d e f a u l t : 
 	 	 	 	 	 b r e a k ; 
 	 	 	 	 }  
 	 	 	 	 / / i f   ( n v . g e t T r a v e r s a l M o d e ( )   = =   n v . T R A V E R S E _ A L L _ C H I L D R E N   )  
 	 	 	 	 / / 	 r e t u r n ;  
  
  
 	 	 	 	 / / L O D : : t r a v e r s e ( n v ) ;  
 	 	 	 	 / * } * /  
 	 	 	 	 / * 	 	 i f ( _ g e o m e t r y ! = N U L L & & _ g e o m e t r y - > s e t S e l e c t ( ) )  
 	 	 	 	 _ g e o m e t r y - > a c c e p t ( n v ) ; * /  
 	 	 	 	 / / _ p r o g r e s s - > u p d a t e (   n v . g e t F r a m e S t a m p ( ) - > g e t F r a m e N u m b e r ( )   ) ;  
 	 	 	 	 / * 	 }  
 	 	 	 	 e l s e  
 	 	 	 	 {  
 	 	 	 	 i f ( _ g e o m e t r y ! = N U L L )  
 	 	 	 	 _ g e o m e t r y - > a c c e p t ( n v ) ;  
 	 	 	 	 } * /  
  
 	 	 	 }  
  
 	 	 	 / / v o i d   t r a v e r s e ( N o d e V i s i t o r &   n v ) 
 	 	 	 / / { 
 	 	 	 / / 	 / /   s e t   t h e   f r a m e   n u m b e r   o f   t h e   t r a v e r s a l   s o   t h a t   e x t e r n a l   n o d e s   c a n   f i n d   o u t   h o w   a c t i v e   t h i s 
 	 	 	 / / 	 / /   n o d e   i s . 
 	 	 	 / / 	 i f   ( n v . g e t F r a m e S t a m p ( )   & & 
 	 	 	 / / 	 	 n v . g e t V i s i t o r T y p e ( ) = = o s g : : N o d e V i s i t o r : : C U L L _ V I S I T O R ) 
 	 	 	 / / 	 { 
 	 	 	 / / 	 	 s e t F r a m e N u m b e r O f L a s t T r a v e r s a l ( n v . g e t F r a m e S t a m p ( ) - > g e t F r a m e N u m b e r ( ) ) ; 
 	 	 	 / / 	 } 
 
 	 	 	 / / 	 d o u b l e   t i m e S t a m p   =   n v . g e t F r a m e S t a m p ( ) ? n v . g e t F r a m e S t a m p ( ) - > g e t R e f e r e n c e T i m e ( ) : 0 . 0 ; 
 	 	 	 / / 	 u n s i g n e d   i n t   f r a m e N u m b e r   =   n v . g e t F r a m e S t a m p ( ) ? n v . g e t F r a m e S t a m p ( ) - > g e t F r a m e N u m b e r ( ) : 0 ; 
 	 	 	 / / 	 b o o l   u p d a t e T i m e S t a m p   =   n v . g e t V i s i t o r T y p e ( ) = = o s g : : N o d e V i s i t o r : : C U L L _ V I S I T O R ; 
 
 	 	 	 / / 	 s w i t c h ( n v . g e t T r a v e r s a l M o d e ( ) ) 
 	 	 	 / / 	 { 
 	 	 	 / / 	 c a s e ( N o d e V i s i t o r : : T R A V E R S E _ A L L _ C H I L D R E N ) : 
 	 	 	 / / 	 	 s t d : : f o r _ e a c h ( _ c h i l d r e n . b e g i n ( ) , _ c h i l d r e n . e n d ( ) , N o d e A c c e p t O p ( n v ) ) ; 
 	 	 	 / / 	 	 b r e a k ; 
 	 	 	 / / 	 c a s e ( N o d e V i s i t o r : : T R A V E R S E _ A C T I V E _ C H I L D R E N ) : 
 	 	 	 / / 	 	 { 
 	 	 	 / / 	 	 	 f l o a t   r e q u i r e d _ r a n g e   =   0 ; 
 	 	 	 / / 	 	 	 i f   ( _ r a n g e M o d e = = D I S T A N C E _ F R O M _ E Y E _ P O I N T ) 
 	 	 	 / / 	 	 	 { 
 	 	 	 / / 	 	 	 	 r e q u i r e d _ r a n g e   =   n v . g e t D i s t a n c e T o V i e w P o i n t ( g e t C e n t e r ( ) , t r u e ) ; 
 	 	 	 / / 	 	 	 } 
 	 	 	 / / 	 	 	 e l s e 
 	 	 	 / / 	 	 	 { 
 	 	 	 / / 	 	 	 	 o s g : : C u l l S t a c k *   c u l l S t a c k   =   d y n a m i c _ c a s t < o s g : : C u l l S t a c k * > ( & n v ) ; 
 	 	 	 / / 	 	 	 	 i f   ( c u l l S t a c k   & &   c u l l S t a c k - > g e t L O D S c a l e ( ) > 0 . 0 f ) 
 	 	 	 / / 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 r e q u i r e d _ r a n g e   =   c u l l S t a c k - > c l a m p e d P i x e l S i z e ( g e t B o u n d ( ) )   /   c u l l S t a c k - > g e t L O D S c a l e ( ) ; 
 	 	 	 / / 	 	 	 	 } 
 	 	 	 / / 	 	 	 	 e l s e 
 	 	 	 / / 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 / /   f a l l b a c k   t o   s e l e c t i n g   t h e   h i g h e s t   r e s   t i l e   b y 
 	 	 	 / / 	 	 	 	 	 / /   f i n d i n g   o u t   t h e   m a x   r a n g e 
 	 	 	 / / 	 	 	 	 	 f o r ( u n s i g n e d   i n t   i = 0 ; i < _ r a n g e L i s t . s i z e ( ) ; + + i ) 
 	 	 	 / / 	 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 	 r e q u i r e d _ r a n g e   =   o s g : : m a x i m u m ( r e q u i r e d _ r a n g e , _ r a n g e L i s t [ i ] . f i r s t ) ; 
 	 	 	 / / 	 	 	 	 	 } 
 	 	 	 / / 	 	 	 	 } 
 	 	 	 / / 	 	 	 } 
 
 	 	 	 / / 	 	 	 i n t   l a s t C h i l d T r a v e r s e d   =   - 1 ; 
 	 	 	 / / 	 	 	 b o o l   n e e d T o L o a d C h i l d   =   f a l s e ; 
 	 	 	 / / 	 	 	 f o r ( u n s i g n e d   i n t   i = 0 ; i < _ r a n g e L i s t . s i z e ( ) ; + + i ) 
 	 	 	 / / 	 	 	 { 
 	 	 	 / / 	 	 	 	 i f   ( _ r a n g e L i s t [ i ] . f i r s t < = r e q u i r e d _ r a n g e   & &   r e q u i r e d _ r a n g e < _ r a n g e L i s t [ i ] . s e c o n d ) 
 	 	 	 / / 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 i f   ( i < _ c h i l d r e n . s i z e ( ) ) 
 	 	 	 / / 	 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 	 i f   ( u p d a t e T i m e S t a m p ) 
 	 	 	 / / 	 	 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 	 	 _ p e r R a n g e D a t a L i s t [ i ] . _ t i m e S t a m p = t i m e S t a m p ; 
 	 	 	 / / 	 	 	 	 	 	 	 _ p e r R a n g e D a t a L i s t [ i ] . _ f r a m e N u m b e r = f r a m e N u m b e r ; 
 	 	 	 / / 	 	 	 	 	 	 } 
 
 	 	 	 / / 	 	 	 	 	 	 _ c h i l d r e n [ i ] - > a c c e p t ( n v ) ; 
 	 	 	 / / 	 	 	 	 	 	 l a s t C h i l d T r a v e r s e d   =   ( i n t ) i ; 
 	 	 	 / / 	 	 	 	 	 } 
 	 	 	 / / 	 	 	 	 	 e l s e 
 	 	 	 / / 	 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 	 n e e d T o L o a d C h i l d   =   t r u e ; 
 	 	 	 / / 	 	 	 	 	 } 
 	 	 	 / / 	 	 	 	 } 
 	 	 	 / / 	 	 	 } 
 
 	 	 	 / / 	 	 	 i f   ( n e e d T o L o a d C h i l d ) 
 	 	 	 / / 	 	 	 { 
 	 	 	 / / 	 	 	 	 u n s i g n e d   i n t   n u m C h i l d r e n   =   _ c h i l d r e n . s i z e ( ) ; 
 
 	 	 	 / / 	 	 	 	 / /   s e l e c t   t h e   l a s t   v a l i d   c h i l d . 
 	 	 	 / / 	 	 	 	 i f   ( n u m C h i l d r e n > 0   & &   ( ( i n t ) n u m C h i l d r e n - 1 ) ! = l a s t C h i l d T r a v e r s e d ) 
 	 	 	 / / 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 i f   ( u p d a t e T i m e S t a m p ) 
 	 	 	 / / 	 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 	 _ p e r R a n g e D a t a L i s t [ n u m C h i l d r e n - 1 ] . _ t i m e S t a m p = t i m e S t a m p ; 
 	 	 	 / / 	 	 	 	 	 	 _ p e r R a n g e D a t a L i s t [ n u m C h i l d r e n - 1 ] . _ f r a m e N u m b e r = f r a m e N u m b e r ; 
 	 	 	 / / 	 	 	 	 	 } 
 	 	 	 / / 	 	 	 	 	 _ c h i l d r e n [ n u m C h i l d r e n - 1 ] - > a c c e p t ( n v ) ; 
 	 	 	 / / 	 	 	 	 } 
 
 	 	 	 / / 	 	 	 	 / /   n o w   r e q u e s t   t h e   l o a d i n g   o f   t h e   n e x t   u n l o a d e d   c h i l d . 
 	 	 	 / / 	 	 	 	 i f   ( ! _ d i s a b l e E x t e r n a l C h i l d r e n P a g i n g   & & 
 	 	 	 / / 	 	 	 	 	 n v . g e t D a t a b a s e R e q u e s t H a n d l e r ( )   & & 
 	 	 	 / / 	 	 	 	 	 n u m C h i l d r e n < _ p e r R a n g e D a t a L i s t . s i z e ( ) ) 
 	 	 	 / / 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 / /   c o m p u t e   p r i o r i t y   f r o m   w h e r e   a b o u t s   i n   t h e   r e q u i r e d   r a n g e   t h e   d i s t a n c e   f a l l s . 
 	 	 	 / / 	 	 	 	 	 f l o a t   p r i o r i t y   =   ( _ r a n g e L i s t [ n u m C h i l d r e n ] . s e c o n d - r e q u i r e d _ r a n g e ) / ( _ r a n g e L i s t [ n u m C h i l d r e n ] . s e c o n d - _ r a n g e L i s t [ n u m C h i l d r e n ] . f i r s t ) ; 
 
 	 	 	 / / 	 	 	 	 	 / /   i n v e r t   p r i o r i t y   f o r   P I X E L _ S I Z E _ O N _ S C R E E N   m o d e 
 	 	 	 / / 	 	 	 	 	 i f ( _ r a n g e M o d e = = P I X E L _ S I Z E _ O N _ S C R E E N ) 
 	 	 	 / / 	 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 	 p r i o r i t y   =   - p r i o r i t y ; 
 	 	 	 / / 	 	 	 	 	 } 
 
 	 	 	 / / 	 	 	 	 	 / /   m o d i f y   t h e   p r i o r i t y   a c c o r d i n g   t o   t h e   c h i l d ' s   p r i o r i t y   o f f s e t   a n d   s c a l e . 
 	 	 	 / / 	 	 	 	 	 p r i o r i t y   =   _ p e r R a n g e D a t a L i s t [ n u m C h i l d r e n ] . _ p r i o r i t y O f f s e t   +   p r i o r i t y   *   _ p e r R a n g e D a t a L i s t [ n u m C h i l d r e n ] . _ p r i o r i t y S c a l e ; 
 
 	 	 	 / / 	 	 	 	 	 i f   ( _ d a t a b a s e P a t h . e m p t y ( ) ) 
 	 	 	 / / 	 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 	 n v . g e t D a t a b a s e R e q u e s t H a n d l e r ( ) - > r e q u e s t N o d e F i l e ( _ p e r R a n g e D a t a L i s t [ n u m C h i l d r e n ] . _ f i l e n a m e , n v . g e t N o d e P a t h ( ) , p r i o r i t y , n v . g e t F r a m e S t a m p ( ) ,   _ p e r R a n g e D a t a L i s t [ n u m C h i l d r e n ] . _ d a t a b a s e R e q u e s t ,   _ d a t a b a s e O p t i o n s . g e t ( ) ) ; 
 	 	 	 / / 	 	 	 	 	 } 
 	 	 	 / / 	 	 	 	 	 e l s e 
 	 	 	 / / 	 	 	 	 	 { 
 	 	 	 / / 	 	 	 	 	 	 / /   p r e p e n d   t h e   d a t a b a s e P a t h   t o   t h e   c h i l d ' s   f i l e n a m e . 
 	 	 	 / / 	 	 	 	 	 	 n v . g e t D a t a b a s e R e q u e s t H a n d l e r ( ) - > r e q u e s t N o d e F i l e ( _ d a t a b a s e P a t h + _ p e r R a n g e D a t a L i s t [ n u m C h i l d r e n ] . _ f i l e n a m e , n v . g e t N o d e P a t h ( ) , p r i o r i t y , n v . g e t F r a m e S t a m p ( ) ,   _ p e r R a n g e D a t a L i s t [ n u m C h i l d r e n ] . _ d a t a b a s e R e q u e s t ,   _ d a t a b a s e O p t i o n s . g e t ( ) ) ; 
 	 	 	 / / 	 	 	 	 	 } 
 	 	 	 / / 	 	 	 	 } 
 
 	 	 	 / / 	 	 	 } 
 
 
 	 	 	 / / 	 	 	 b r e a k ; 
 	 	 	 / / 	 	 } 
 	 	 	 / / 	 d e f a u l t : 
 	 	 	 / / 	 	 b r e a k ; 
 	 	 	 / / 	 } 
 	 	 	 / / }  
  
 	 	 / * 	 o s g : : r e f _ p t r < P i p e L i n e M o d e l O p t i o n s >   _ o p t i o n s ; * /  
 	 	 } ;  
  
  
 	  
  
  
 	 	 / / 	 c l a s s   P i p e L i n e M o d e l D r i v e r   :   p u b l i c   o s g D B : : R e a d e r W r i t e r  
 	 	 / / {  
 	 	 / / p u b l i c :  
 	 	 / / 	 P i p e L i n e M o d e l D r i v e r ( )  
 	 	 / / 	 {  
 	 	 / / 	 	 s u p p o r t s E x t e n s i o n ( " p i p e l i n e m o d e l " , " m o d e l   d e f i n e d   f o r m a t " ) ;  
 	 	 / / 	 }  
  
 	 	 / / 	 v i r t u a l   c o n s t   c h a r *   c l a s s N a m e ( )   c o n s t { r e t u r n   " p i p e l i n e m o d e l   r e a d e r " ; }  
  
 	 	 / / 	 v i r t u a l   R e a d R e s u l t   r e a d N o d e ( c o n s t   s t d : : s t r i n g &   u r i , c o n s t   o s g D B : : R e a d e r W r i t e r : : O p t i o n s *   o p t i o n s ) c o n s t  
 	 	 / / 	 {  
 	 	 / / 	 	 s t d : : s t r i n g   e x t   =   o s g D B : : g e t F i l e E x t e n s i o n ( u r i ) ;  
  
 	 	 / / 	 	 i f   (   a c c e p t s E x t e n s i o n ( e x t )   )  
 	 	 / / 	 	 {  
  
  
 	 	 / / / * 	 	 	 u n s i g n e d   i n t     x ,   y ,   e n g i n e I D ;  
 	 	 / / 	 	 	 s s c a n f ( u r i . c _ s t r ( ) ,   " / % d / % d . " ,   & x ,   & x ) ; * /  
  
 	 	 / / 	 	 	 u n s i g n e d   l o n g   l o n g   g e o K e y ;  
 	 	 / / 	 	 	 i n t   l o d = - 1 ;  
 	 	 / / 	 	 	 / / p a r s e F i l e N a m e ( u r i , g e o K e y , l o d ) ;  
 	 	 / / 	 	 	 L o d M o d e l O p t i o n s *   l o d M o d e l O p t i o n s = ( L o d M o d e l O p t i o n s * )   o p t i o n s ;  
 	 	 / / 	 	 	 l o d M o d e l O p t i o n s - > p a r s e M o d e l N a m e ( u r i , g e o K e y , l o d ) ;  
 	 	 / / 	 	 	 o s g : : r e f _ p t r < P i p e L i n e M o d e l D r i v e r >   m o d e l O p t i o n s = n e w   P i p e L i n e M o d e l O p t i o n s ( g e o K e y ) ;  
 	 	 / / 	 	 	 o s g : : r e f _ p t r < M o d e l >   n o d e = n e w   M o d e l ( m o d e l O p t i o n s ) ;  
 	 	 / / 	 	 	 i f   ( n o d e . v a l i d ( ) )  
 	 	 / / 	 	 	 {  
 	 	 / / 	 	 	 	 r e t u r n   R e a d R e s u l t (   n o d e . g e t ( ) ,   R e a d R e s u l t : : F I L E _ L O A D E D   ) ;  
 	 	 / / 	 	 	 }  
 	 	 / / 	 	 	 e l s e  
 	 	 / / 	 	 	 {  
 	 	 / / 	 	 	 	 r e t u r n   R e a d R e s u l t : : F I L E _ N O T _ F O U N D ;  
 	 	 / / 	 	 	 }  
 	 	 / / 	 	 }  
 	 	 / / 	 	 e l s e  
 	 	 / / 	 	 {  
 	 	 / / 	 	 	 r e t u r n   R e a d R e s u l t : : F I L E _ N O T _ H A N D L E D ;  
 	 	 / / 	 	 }  
 	 	 / / 	 }  
 	 	 / / } ;  
  
 	 	 / /  
 	 	 / / R E G I S T E R _ O S G P L U G I N ( p i p e l i n e m o d e l , M o d e l D r i v e r ) ;  
  
  
  
 	 }  
 }  
  
  
 # e n d i f  
 