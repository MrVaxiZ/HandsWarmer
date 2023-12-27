Shortcuts used in code and what they mean :
- 'NTBLA' = 'NeedToBeLookAt' (Part of code that works but no one knows why and should be checked)
- 'VTBC' = 'ValueToBeChanged' (Used only for debug purposes DO NOT leave it in production code unless it's life or death situation)
  This one can have additional parameters like '::P' so it looks like this 'VTBC::P' - where 'P' stands for 'Purpose'
  Other Parameters :
    '::HF' - 'HotFix' (Something broke and had to be fixed asap, has to be later investigated and properly fixed)
    '::W' - 'Waiting' (Developer doesn't know what value should be placed here yet)
  If needed add more.

- 'Debug/END Debug' = (Methodes or parts of code that are being used for debug purposes, can be left in production code just make sure they are not being called)
- 'TODO:' = (I think this one is obvious)
