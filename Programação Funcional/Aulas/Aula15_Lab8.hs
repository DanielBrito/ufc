module Aula15 where

import Control.Applicative

import Aula3 (myIf)

-- Observe a seguinte definicao de map

myMap :: (a -> b) -> [a] -> [b]
myMap f xs = xs >>= pure . f

-- Questao 1
-- Implemente filter utilizando >>=
myFilter :: (a -> Bool) -> [a] -> [a]
myFilter p xs = xs >>= f where
                f x = myIf (p x) [x] []

-- Questao 2
-- Escreva a funcao join. Dica: >>= e id
myJoin :: Monad m => m (m a) -> m a
myJoin = (>>= id)

-- A combinacao de Maybe e IO eh muito natural, uma vez que
-- interacoes com o SO podem falhar por motivos diversos.
-- Observe a funcao a seguir (bem rudimentar)
confirmPassword :: IO (Maybe String)
confirmPassword = getLine >>= \str1 ->
                  getLine >>= \str2 ->
                  myIf (str1 == str2)
                       (pure (Just str1))
                       (pure Nothing)

-- No entanto, eh um pouco doloroso trabalhar com essa
-- combinacao. Vamos facilitar a nossa vida.

data IOMaybe a = IOM (IO (Maybe a))

-- Questao 3
-- Faca IOMaybe um Functor

instance Functor IOMaybe where
  fmap f (IOM iomx) = IOM iomx' where
                      iomx' = fmap (fmap f) iomx

-- Questao 4
-- Faca IOMaybe um Applicative

instance Applicative IOMaybe where
  pure = IOM . pure . pure -- cada pure se refere a um contexto.
  (IOM iomf) <*> (IOM iomx) = IOM iomx' where
    iomx' = iomf >>= \mf ->
            iomx >>= \mx ->
            pure $ mf <*> mx -- pure poe o Maybe dentro de IO.

-- Questao 5
-- Faca IOMaybe um Alternative
instance Alternative IOMaybe where
  empty = IOM $ pure Nothing
  (IOM iomx) <|> (IOM iomy) = IOM iomr where
    iomr =  iomx >>= \mx ->
            iomy >>= \my ->
            pure $ mx <|> my -- pq Maybe eh Alternative

-- Questao 6
-- Escreva a funcao lift
lift :: IO a -> IOMaybe a
lift iox = IOM iomx where
  iomx =  iox >>= \x ->
          pure $ Just x
