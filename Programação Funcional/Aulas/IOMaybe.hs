module IOMaybe where

import Control.Applicative

-- Queremos apenas criar semanticas novas para tipos existentes
newtype IOMaybe a = IOM (IO (Maybe a))

instance Functor IOMaybe where
  fmap f (IOM iomx) = IOM iomx' where
    iomx' = fmap (fmap f) iomx

instance Applicative IOMaybe where
  pure = IOM . pure . pure -- cada pure se refere a um contexto.
  (IOM iomf) <*> (IOM iomx) = IOM iomx' where
    iomx' = iomf >>= \mf ->
            iomx >>= \mx ->
            pure $ mf <*> mx -- pure poe o Maybe dentro de IO.

instance Alternative IOMaybe where
  empty = IOM $ pure Nothing
  (IOM iomx) <|> (IOM iomy) = IOM iomr where
    iomr =  iomx >>= \mx ->
            iomy >>= \my ->
            pure $ mx <|> my -- pq Maybe eh Alternative

lift :: IO a -> IOMaybe a
lift iox = IOM iomx where
  iomx = iox >>= pure . pure