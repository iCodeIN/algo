n a m e s p a c e   n t t   {  
     i n t   b a s e   =   1 ;  
     v e c t o r < i n t >   r o o t s   =   { 0 ,   1 } ;  
     v e c t o r < i n t >   r e v   =   { 0 ,   1 } ;  
     i n t   m a x _ b a s e   =   - 1 ;  
     i n t   r o o t   =   - 1 ;  
  
     v o i d   i n i t ( )   {  
         i n t   t m p   =   m d   -   1 ;  
         m a x _ b a s e   =   0 ;  
         w h i l e   ( t m p   %   2   = =   0 )   {  
             t m p   / =   2 ;  
             m a x _ b a s e + + ;  
         }  
         r o o t   =   2 ;  
         w h i l e   ( t r u e )   {  
             i f   ( p o w e r ( r o o t ,   1   < <   m a x _ b a s e )   = =   1 )   {  
                 i f   ( p o w e r ( r o o t ,   1   < <   ( m a x _ b a s e   -   1 ) )   ! =   1 )   {  
                     b r e a k ;  
                 }  
             }  
             r o o t + + ;  
         }  
     }  
  
     v o i d   e n s u r e _ b a s e ( i n t   n b a s e )   {  
         i f   ( m a x _ b a s e   = =   - 1 )   {  
             i n i t ( ) ;  
         }  
         i f   ( n b a s e   < =   b a s e )   {  
             r e t u r n ;  
         }  
         a s s e r t ( n b a s e   < =   m a x _ b a s e ) ;  
         r e v . r e s i z e ( 1   < <   n b a s e ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   ( 1   < <   n b a s e ) ;   i + + )   {  
             r e v [ i ]   =   ( r e v [ i   > >   1 ]   > >   1 )   +   ( ( i   &   1 )   < <   ( n b a s e   -   1 ) ) ;  
         }  
         r o o t s . r e s i z e ( 1   < <   n b a s e ) ;  
         w h i l e   ( b a s e   <   n b a s e )   {  
             i n t   z   =   p o w e r ( r o o t ,   1   < <   ( m a x _ b a s e   -   1   -   b a s e ) ) ;  
             f o r   ( i n t   i   =   1   < <   ( b a s e   -   1 ) ;   i   <   ( 1   < <   b a s e ) ;   i + + )   {  
                 r o o t s [ i   < <   1 ]   =   r o o t s [ i ] ;  
                 r o o t s [ ( i   < <   1 )   +   1 ]   =   m u l ( r o o t s [ i ] ,   z ) ;  
             }  
             b a s e + + ;  
         }  
     }  
  
     v o i d   f f t ( v e c t o r < i n t >   & a )   {  
         i n t   n   =   a . s i z e ( ) ;  
         a s s e r t ( ( n   &   ( n   -   1 ) )   = =   0 ) ;  
         i n t   z e r o s   =   _ _ b u i l t i n _ c t z ( n ) ;  
         e n s u r e _ b a s e ( z e r o s ) ;  
         i n t   s h i f t   =   b a s e   -   z e r o s ;  
         f o r   ( i n t   i   =   0 ;   i   <   n ;   i + + )   {  
             i f   ( i   <   ( r e v [ i ]   > >   s h i f t ) )   {  
                 s w a p ( a [ i ] ,   a [ r e v [ i ]   > >   s h i f t ] ) ;  
             }  
         }  
         f o r   ( i n t   k   =   1 ;   k   <   n ;   k   < < =   1 )   {  
             f o r   ( i n t   i   =   0 ;   i   <   n ;   i   + =   2   *   k )   {  
                 f o r   ( i n t   j   =   0 ;   j   <   k ;   j + + )   {  
                     i n t   z   =   m u l ( a [ i   +   j   +   k ] ,   r o o t s [ j   +   k ] ) ;  
                     a [ i   +   j   +   k ]   =   ( a [ i   +   j ]   -   z   +   m d )   %   m d ;  
                     a d d ( a [ i   +   j ] ,   z ) ;  
                 }  
             }  
         }  
     }  
  
     v e c t o r < i n t >   m u l t i p l y ( v e c t o r < i n t >   a ,   v e c t o r < i n t >   b ,   i n t   e q   =   0 )   {  
         i n t   n e e d   =   a . s i z e ( )   +   b . s i z e ( )   -   1 ;  
         i n t   n b a s e   =   0 ;  
         w h i l e   ( ( 1   < <   n b a s e )   <   n e e d )   n b a s e + + ;  
         e n s u r e _ b a s e ( n b a s e ) ;  
         i n t   s z   =   1   < <   n b a s e ;  
         a . r e s i z e ( s z ) ;  
         b . r e s i z e ( s z ) ;  
         f f t ( a ) ;  
         i f   ( e q )   b   =   a ;   e l s e   f f t ( b ) ;  
         i n t   i n v _ s z   =   i n v ( s z ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   s z ;   i + + )   {  
             a [ i ]   =   m u l ( m u l ( a [ i ] ,   b [ i ] ) ,   i n v _ s z ) ;  
         }  
         r e v e r s e ( a . b e g i n ( )   +   1 ,   a . e n d ( ) ) ;  
         f f t ( a ) ;  
         a . r e s i z e ( n e e d ) ;  
         r e t u r n   a ;  
     }  
  
     v e c t o r < i n t >   s q u a r e ( v e c t o r < i n t >   a )   {  
         r e t u r n   m u l t i p l y ( a ,   a ,   1 ) ;  
     }  
     / /   T O D O :   i n v e r s e   p o l y n o m i a l  
 } ; 