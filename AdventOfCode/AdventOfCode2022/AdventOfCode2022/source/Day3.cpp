#include "Day3.h"

//Includes.
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>
#include "Timer.h"

//Functions.
Day3::Day3() {
	Run();
}

void Day3::Run() {
	//Start code.
	std::cout << "-------------------" << std::endl;
	std::cout << "Day3 code running: " << std::endl;
	Timer timer;

	//Get a list of all the backpacks.
	const std::array<std::string, 300> input = {
		"lflZfgnSnlmmlgGfjGthQPtLNsQhvbHLLpSS",
		"zrCVDVFMJTCTcCJMwCThWbtbpbWpPbtbHPLQssLsHP",
		"rBFcrwFzFwwVDcDrzTzJfnRGjllBdGZnnZfhqmdn",
		"FjpnFRDmbRtnbJrFJmSTsGShWVhGqGVVsmqs",
		"ZwPvNPdzNZwfzBNLdNNNNcLvhnQhqMTVsTGSWSqGqTdVWhMT",
		"vgLZHfvLffNLPbggnrbFpJnCbC",
		"hzJzGjGfqmGtDQtDSvVV",
		"plpcMBNBcCTlTgCMbvtrsSVsVJDJlrwDQr",
		"McHBMMcTTHgJnWqnRqjzZnnRzR",
		"ppvsGZhDGprrSjSllwfZ",
		"TTFMMFJMgMHmHmdqdSvNqlSSSNJv",
		"mgBPHTRWFRVcpvsVttppbv",
		"ZZDssfMDMtqqppZLLJzmzSTwNJplTSgpgm",
		"BdCRRHFRbccWWBvBHCdcJVngNVSvTgVNzgNNVmnz",
		"QHFFrBdcGtqPmmQh",
		"qLvQFRgLSSNgqQvRrqLTQvLttwDBFWDwjwFttDdlBBwBwM",
		"nbsmZnbmHbZVCGPVmHWtwlStBDtwBMtwWHMj",
		"CnCbhGCPpPCSnZmrgRNRqNRrLNgrzh",
		"vgLWWHRNLnWwLggWzwLFFzMmBMRMhMhTbhsmmsbbmQTm",
		"rScpJJDDpjtSDPPPJDpjqPCHBBtlTdblmmlhBsMMmTsbmtsl",
		"GHZHCPprSSwgvWNVwVZv",
		"dMrCMJMqvtdFwcjczjQzThtm",
		"gGbLblLpZlHvllQhlQwcjT",
		"GHRWvPRbPHPRvNGbvdRBqdqBBfRqBqnrfF",
		"VsHcljlbhmHbHHlcjVcVShJSCdJCfMrMMQDfRNFCfMRGfNrQ",
		"tGtvLtpgBTGvDMMRdMMgdCNM",
		"pnGnGqGtvtzTLjWqmSSjHhWhWs",
		"NJTDntDNDVjNnjBfjjjcCZCZcVqCSCLqcSScCc",
		"zvhgRgQvvdllgQbHghlvHrRHSScBCRqqwCLGqSMCZCGGGqMZ",
		"pvvrHzdgvlgzQphQsDFmnsNTTtjfjJJmPB",
		"ScnSZSZZlmjmHjjWHHWZftJVJpppwtVVnLJtnptnwt",
		"CFFlQBbbPQqrBwJrJJrGJD",
		"PgTqRddFzgdRPFFbFgqQFgsSjfHWfSHmSMWcjZlmZmjTZM",
		"lzBRtctbnBRBRBBWnDnDWjlLVvwGMrvwrHHQHGmDvHQvHGrV",
		"FsTgFCTSgsCNspzhCGMfTHQVwVMfMmMmrH",
		"hSdSFgghhqpRbLqjntqnPz",
		"DCDnNGFFDQdQmVDNdFVNFccpJLHWSvPLrvvvPtGGhSttLv",
		"sBgTzzZqrBlfljslWBhvHSvPBhSBJSSL",
		"lRlTgMzlzrwRrnmbCMCFnNVMnc",
		"MJQJMJHBrsdrHwts",
		"dbbSVGgbjVqGTVfqddCTpmWWcprgNgWmcWwWswpN",
		"LPdGGdVGPCVdLBlBMlDRRRMD",
		"vdcwZLTdTFFRDHVgmpppMmqZ",
		"jGPzCnQPjlsDVqDpqDHbgP",
		"BjWJrlGQQzrCzBzlzBCGBznzwNRNcwLJdwTJFTHRSTvtLcNN",
		"ngrgqTjJJZnjFJpnqnnVTLzBbbHbLQdLHLHbrdHdHG",
		"lNcltCCtvftfWssPbMQdMBzhbbcBDLdh",
		"PRtWsQCmWsmSsCNCSvCSWlspwgqjqmqjTpnJZwnZVpFwgq",
		"PjWjGDCjmrmWPNmvWDWFmgCNfVJRLfJRfLDLJQlfHplpRbfR",
		"MtZMtcSbccZshTtQTVVTpzHlLRRQLV",
		"cZhbwMnwqsqnhnqtMBnvNFrnGPNPPmgPGCgW",
		"WBjWjWjqZwQJnJZCZZbf",
		"StHSDRPHHcTrTrJpLCCMbrqnJn",
		"RvTTvGqcqTFvSvSRDHvRjlhgWBWBdhjwjGgNjhlj",
		"FSbCqcFsbCPtrcrqhCScbshMjHDGGWBLHBnjGLPBHGGBGnHj",
		"flQdlsgQgGnQHBHjDn",
		"vllgRZdmvsvpgdwZgzJdwRmprqccSFcSShJbTSttqMCrCCch",
		"GwwgCtvHgwcHVVDqpWdfnqVv",
		"sllBsSNBjSrLfqhLgjfqhL",
		"ZbQbZQzgQQPSblBggNQRHGZHHCmwmHFGGcwtJm",
		"CmGVGBTVTmmTWTNLLCVgCSFvDQppQQDDnDQDJpMggfnQft",
		"RrtdqtldPbHzRbnjRfQZjJfMDnMj",
		"wcwhccqrdrrlFmLGCwCtSwtL",
		"pzZznZphZnpcNWSwGwVVPzrPrG",
		"lgFllLLltgbDsrBCwrjWGmwmtw",
		"MgJbDLlMQRJccchrhc",
		"wbbjzZhdGDwLzZSBWqqHmZgssCWqFtMZ",
		"VRJccfvPlTTlQlHQCWQhMMhCCHqQ",
		"RlVfVJcPTVTfvvvJfNJVlcBjGjwhSLdBNGGnjLLBwzGb",
		"bvpqHMVTTpZnqnWRQQQw",
		"tfhFFdSFggfhbldhhZcnRscRcQmnRs",
		"DPzgFJzFLfFbFSgPFgdPglMHpvBpHTCMGpjvMMpLvvNG",
		"JggGLQgQpLpSPRJgGPSnGlFTDBjjRFvRjtBFjWvFjqRj",
		"cmHhZcMHcWjrTBjrvm",
		"dbHwdNNHhwTNThZHdlwQJJwngpgnJGnSPw",
		"DbZjVfjVLhZDLpWPHpMZPmmGNp",
		"lFcJJGcFqnBFqwJCHHMmNHPsdCNp",
		"BlwccRQtBwBrwLGbGhGggzLgzR",
		"RBhZPjlWqgbNbgGLBr",
		"MzSmSzpFdHwpswzzHnzjnvLCbgtrtLGLbJLLJNtJtbwJ",
		"MsSHdmMdpFfmFjpfcPWRhRVZfWQThZ",
		"mqmssPCFhhsJccVg",
		"FTttfwdjjHznJgfngpnc",
		"dNFTjQNRtRNQldRNrRdHMRrlPZqCGlGBCqqZmmbPqDmDCmGW",
		"ZJVRRZZJRcvmPhCJrvhm",
		"PPWQDTfWbnnstlCGvjGrWMGMvr",
		"TbbwddndsnsfDpwFqZFVHBVPqc",
		"tFmpJmgJJgmFDWgRgFrrlGSltSQvZChMtCMM",
		"TLcZHsjLVNBwGQCCGlsCShvh",
		"nqNdwwccBwVLwjjDznZzppbgzFZfDF",
		"qsTqCCCszjlqTssBShlQSSZFgZZhgB",
		"LDPmVgDDJdLPrPgLgPZSFZQfhQGGBQJcSFJS",
		"mvmVbVvtggVtvgdLVvtmptCsNTtjRnpRTTjpsqCp",
		"BdNPLnmFvLFNgnmBmnFGnwSZZZWwqWgqjwWssTHWSS",
		"bJhMzhbVMbDCcVpZtjHMqTMwtttSjH",
		"hzclfCppVqQfbzQVbpzPQLNFBdrvdNGGBnmrmP",
		"nLVLzBDJCCHqdLncqVJgSsDlGsbssmvvvbvbff",
		"jMNHFWNTZZNwMPrPWrrPMMrrvSllbgsllfgbgvQsvGmglZbv",
		"RjPjrjRPtNrwHhBtncCJtJtL",
		"jbhhjhNjvqNbmjMjqhtCFdmPFdlzJzfFfJQJfR",
		"GBBZWrZWgpSsnSngrrSgHzFzFFdClzfFQFlRZftQPR",
		"TrGTrGWHpHWGHWVWsngprHpLbLLVvcqMcNbVNLhwVNbtNb",
		"sQDvDmDLQFDRsdchzhBczLhhPhVz",
		"MbGGMjjGZSjvfHvHSbfwBqcPnqqcPVhPNnqnzjcn",
		"ZwMMHrWvSHbfJfTrbJwSMMfMsQDtsFRptlpdCRpWmptQDRmC",
		"TwMHdcTznLqzTrHdzzzHTdgMRQWRhJhNjjvgQvQQWNjl",
		"tbfsVbDCVSSDtSPQJWPvRNhQtghN",
		"FVGBpGCVFCbfCbVbZCSHqmwqcqLcdHJGwHqqTd",
		"lTlGfjLGwHNMggscsDRwsC",
		"MrFtrzZZPZrtVQtnrrFdQhhDPDSphgDRhDcsCCgWpW",
		"ZJmJVzVVJFHfGbqJGMLv",
		"zsFZVjzlHPfTzGfLGtv",
		"mdrrmdMMcBcmNqNbPqfRDLPWPlqTWD",
		"BNQhmmrBrQghgSmNBQQSmvwssjZZSJHljJFFHZJvZV",
		"rLZCsZdMJfdNCsfZMrLdFmssnwgTRQgBBwgRwcngTNVRVQjV",
		"StqDHlStDPgRTqcwjT",
		"GlDGDhbpHhvSHWlzbWlhpzhJdrFLrCLmvdmFZsmJJjJfdv",
		"pJHJMJsJjSMFdHhszFvMhlmmGNlSmmBGllWmVlwcTw",
		"ZqZRDrZCZDtPDPDrCngrnnPQGVmGHVBWGWtGmWVwVlmTlGNl",
		"ZQPgRqrrQPqLnrLMvLphHdvdjpJddb",
		"NwbBjljFbcjtTcccqW",
		"RHZrPHPpNgZTzTqc",
		"sfrPdmPdpsmPPPrfQPVGlwGVBwbGVnFlNQCG",
		"hQdNTlzhdTvrhdnTBqcWBLsBHgWQgBPg",
		"zwzRDbDfqZBLHDLB",
		"wFbFmjjRzfmjGGMGMfmJwwGCCnvNhpvSCNnrvJvCprnnSp",
		"zshNNJbwGFJfGJzzzNRnHGnCnRHcRPgTmPmn",
		"LMDVtZLStrrZClBrVDllLSBWRPTPPRRPmgWPVmPTPHTWgR",
		"SDSqLMlrtLlLtrBqBdlMZjvffCNzwvhjvvzhdfNhvf",
		"SLQmGBmhLSLQTBGBGwdwpJjwwQjwcVpJZJ",
		"sNrWrWPNbHghrbgnNNzbWbFWdZpMpzVpdMZMzMMVZcwwJdwd",
		"frrPNNWshWhhHDvDGDRSBSRvttqv",
		"FJqpgvhJJRjFjZTqDsMHrzwjsSsSszMrMm",
		"PPPQWGtnbbfBmPsFswwsMrcc",
		"QfBtbldtWQfbWbnfGlFqZppvpFZZLhFlpq",
		"ZqSMZHHCMpHTZTWmFTFZPZQJBgVGVJQvVVSDBvBtcBBG",
		"RNsndwsNjsbsgGCgjQBttcBg",
		"NRszRRNzLNNNwNfhCCrfdmTqFZllFFHFFpWhlTmWpq",
		"llbbzDmSspGRpHpzsldzRRsVtFBBFJMMVVFLTTTMVtLTDM",
		"cqgjqvNgvqCjQZqgGGnhMTnMJVLBLMtFhhVFWB",
		"PfGGvQrPCjvjZgGCCCZZZbSmmmHlRpprlHrHwssSRr",
		"mRmpFpWpfMMgLnmS",
		"CdCsqzdRzqStLjSqfMnL",
		"wQRHdTzCQbzCwsTrZBlFZGpVlpFGQD",
		"qnMTnTVSTPTHTHcMZMvVpmppmFmVzFLLFLlFpG",
		"gBjDsjRRwhDDghthwwWZwLmpmwWWLWLbGZ",
		"NhZtZtBgPTNJJNTS",
		"jLjjmpHvzvZrfzQjmfHHWrfbqblLsSlTsqsgqPJbPqVglb",
		"FBcCwDwtwgcgnCwcGchtJSsRqVRVJPPqDlbSDRPq",
		"MBhthFNtMGCwhcwnpQfWjNrQprpvzpgQ",
		"RfCnWfnhCbwHgWjzBgzB",
		"PsVqDsSTshsgszpsph",
		"DPDvTVtTShhSZhmqSvLlQJFnQJJZnbCnlCCZ",
		"pRRdJngltnwwvTNSWqWffqgBqD",
		"HQGcsdrjzMDDBfGMGG",
		"FLhsdbzCLLHjhntpVnRPRvZV",
		"gZNwQHHNRlGvhvhGRvRb",
		"dpSSBDrzdCfcSzfrzZrfCfMbthWWWPttDthvMFWvvvPj",
		"ZdpBpZCrssBJZfSJBzBdCTcnmQwmnVVlmqTQTTQlHLwNnN",
		"ssCpTttVVVpzZDVvRpCsRtDgWBWBBFBJvvJHMBghGghrMJ",
		"lwLmNNLwSblbmSQLfhJHZgHrHhhJJhHHmW",
		"QLSdbdPqndlNlLdSLNQncpRtRTcRVTPPZRCjVCcc",
		"wzzJclzcTThvWSSCqRlQSsNN",
		"rDpVjpVVDpsQSRDRfQmm",
		"GLbjrLpFbgLVLLgdbjVpchcFZhvBwJvtvtJcZwRB",
		"wPgZgLVMfWVTgmTZZZftJjtfjtJCcdpjdCqc",
		"zGGbQQnQGvBBhGQvvvBBSBvQdhdqqCpdddDmJlCcDjCtJdmJ",
		"HszzHBzQBSmGSwTWgswZPWTVgZ",
		"GDFvzCFdrszSdNJrFfjjfqZjRfsjpqmcwZ",
		"WbbVtVnBPWMgBLMBnQQnBQHcjfjpZRwqcwMfcNTZRqqNmT",
		"WQQnVVPHtggLghWWhHnPVQbvlJhSlrvJDlFGJDdDCzGNFF",
		"dVhTBjBHtTVqWRJZRqhJZQ",
		"brSDTbDfcCwDzfCSbwMQnlqCRJnMgWWnZngM",
		"DFwNSrwNwbDzbFTTFtjmBpVdGpHs",
		"dPQfdfTzDrFDmFDBgBFj",
		"RlJRclcswJRvnwPcpjbjbbCZjFjbBmsbFZ",
		"pqncGlcRJpHGpllGHhvPhRTHrQrttVVfrdQzfrTdftfV",
		"RCzTzRMTfCfRRDzRfhSmZZlCslBbZZBVtZBZsqBL",
		"nvvJPpdcFnPcWnFnVZvBqVlZMbZBNVlV",
		"FpWPMdjdPhSTmwfSjD",
		"NDJjNHLLNWjcLLWCLJLZjLDtRqqtgtMqgtqnRqnSRgggtZ",
		"BwrlfFwmQwhwfPBFhsBdFmbQggCgqQVtbRSqttqMngnp",
		"llPPwsPlGshBJGWJLcHvCzNv",
		"rBvTmwdTSbnrvVWsWVftGfJQGT",
		"gNRLLjlPRWnFVRFDFW",
		"lpCpPNZqZCdvdppnSnBr",
		"ShRdCrJgHClZJtZDGMMz",
		"LvqVVTTNbVPLQNFTnwwMtzFZGDDwmtnM",
		"VLbNvpPvTNVqVbbNpbVPGNLPrRWrcRCWdSrCjWSHcHSdWpCh",
		"tNmZnLSZPFLDnLTmhJMWczQdhmWhWH",
		"bGqbgrpsCsWhcChNQfJz",
		"vwlNbppsRGRRSSSDvjTjLZjZ",
		"zgMZhgfBtftSZQQmLHpSWH",
		"cdqcqnrJVGjjqPVjrPnfpJmsQHQQpsSsbsSDmm",
		"NNnrNqNlrNcPTlBvBvgggfMv",
		"llPrrLHBHCrRRBjrHCjBdrPmvJZzZgZbmgJlZmZhMhhmvh",
		"pNDstVtNtGFNSDFScQtfwzzFJwmJhgqzbMwqZJmh",
		"fpNsptGtQcTsSTccprddCWPrWdTRBMMCMd",
		"TTtDVqTsTcJFgbCqmbCq",
		"NWZQnllzfBFZPBGWQGzFPFRNNgHbHrrwbNrmCbggJRHR",
		"nBZjGFjMQBMPZnjfWjstpcctttvVtcTttMpL",
		"qphVCCwnHqhnRVznFwvLtBTLDTWZtwLWWS",
		"JmdlsdlsjfJfrtjTcvtctDZSSB",
		"rsmfPGbrPbPJfPmrsgMrdJdlFTHhFCqhNqVHnNHHCFznhphG",
		"JsWFMJJzrhSSdFdldmmdmdQc",
		"qLLgCVTgLbBvqsQPVdQGcRRmQmdc",
		"bBCBgCCDbLDqTvqqjpShHfzrzMfjtHHSHsfz",
		"nvFSBFlvvgQFFBzQnlQglmRRzqwsrrMJJMrsMqrfrwzf",
		"CjZNCNhLDNbPZZLZZhwVjpcfrqRhsdJqdsshRTTdqJrJ",
		"jNNDDppjpjDWNVLCVVDpGVVPBFtlSQFWvvQvSSQHSgwQnvtB",
		"WhrQWBRWwhzgmpnSpH",
		"LqMVsJVvFMJLJMsfNjsTJvCgFbSmzgpSHzmngHbGPCbm",
		"jvMjjtqVjTRnwZQwBWwt",
		"jfTWSGSTTWhgcngQfbtJfNzztBQBzz",
		"pVVwsdppRVPLVmPsVVHsjPLPzQdzBzQFzFBNNrJZZQBzbbFF",
		"VmsqHmjHmpvGDSWDvlclSl",
		"PNZfTFSFfTFGCHqqmbFm",
		"WjzRWrjVgnjzplrWWjJVppgGPGsgstmPCCtcmssQqGQt",
		"pzjzJVvnzJjWvpPlnVRVrvnlTDLNNhwfdNZLfMZLwLhTNvTw",
		"QFrQZMFVrVpVszzcNTdMRCCb",
		"SvljGmlvLfwLhLLLHlHdNzsRthhbbRccRCRNbC",
		"LfwlDmlvGBSjjlLLgpPpFJqgQndQgZBJ",
		"RBjPRHdjPfqQcfhcdv",
		"SngFcJZJlcnctSlhhsQvGsDGDsDnfs",
		"pSmFgSWNJFNtStrmNtpCCjPVcbjjHbcWTBHBHL",
		"vGjqCPqNPGFGNftLwmZwfQNTLp",
		"hrdBCSHcCJJcCBShJswmLQpLbbQZTLLJmmZp",
		"BdHHSzrBWdzchzzCcdzHddcDVWFnjPjllGggVlWljPFFFWPM",
		"hBtZZnpbhbPZJbnhDtPnpBtpfjfNNzrrCzjFzFzFTjfjjWzJ",
		"gHllMqRSmqcqMTdggMqHlcFzRrFQWNfvrRvzQrWjWvWf",
		"gwqlgHmmdsgwlwMHZtpsbBbtDBThbBht",
		"CsDLFFLFCvczsCsJrCrJJLRgbQQgmMmPbDDQbPnMgMmg",
		"VlwNBNVhjNVNWBwWjtbRMRZzPmQnfQMPnlZP",
		"VWWSSwGTwtwWWNVwwpqJJrcJGvzqCJCqJF",
		"wLwSSbzwCvddlvvlSj",
		"THnQnnHttcvpQzrZRllZ",
		"sTntBHTnVbPbgzsbgL",
		"FwHgrHvFQQwpHhNhTBLdpNNNLd",
		"fCGqCVtszfSslCSzSGsfCssjNTqLTdmjNLBLdnTTTMTjTg",
		"DccfslfgRSSVVzlcSVtzDRVHwQZFrwwvwFWbbbRRWwrFJb",
		"CwwWwwFNRpFFpZQHtsmfqbQDTQTTqb",
		"VcjzLjGjzGjGjVjLdzqmDqHrsmsqGRrHqGqH",
		"RjdVlgdnljlBnSgPCpNwwMWwMM",
		"tCCtqtbPGzsSQVzQTq",
		"mzMmHMpRsRQTsFFV",
		"DpzDwgdMzMLppNmNpDpfgrbhLcGtPrbtrbrbhnbBcC",
		"BvsQBBBLvDQGjDvSQLTvrHprHlRpVlVllgRbRbHPqq",
		"MMMMCpfJFZZMmCzwpVPCWRtHgqWgqClgtt",
		"FwzmfzhFFdFcpvSDSBDThs",
		"fQrGQbFFFrHHtlHPclzzPLvc",
		"mTnwpNCCqMqjmCThpTpSvvtBczstlLznvsztsPPP",
		"mCpTNhmmpCqCmjmpTjmLCpSJQZVfFVrDVfffFFgfgJQFdbgG",
		"GmWjRBSfttcGfRcSclVVJqsTMllsgJVMVZwV",
		"pPFNpfNCdNzCVMTTNqVssqJN",
		"dzPfHCLLhdjjLGRnmnmr",
		"GPhPfGWgggfslffPsVPGsqJMzLQJtBprwQJJGQwLpQrw",
		"ZNdmvbDDbNvHbmZCcJQwMmzMwWWQrrwttp",
		"bvdDNdnvNbnHDdnDHHRSbnqhqhWfjWFVTVhRVjfjFTfP",
		"hTThfWNCDRfsVCDhpgzgbpPZZwbnZQns",
		"GSjGGcCBGmdjdSlGBcmZwzJzpPpJzwPwQbzgPd",
		"BGmcrcStcMMMmrSLmSMCvFVRFDhfFhhNDWWTqFqTvf",
		"ZmjDTTbmqQCCQQSwvhsL",
		"FGVJPmPmtRVRsCvvRLwwhC",
		"JgdHJgmfbjzTpTMf",
		"fTbsVCsssgLNrfNrgm",
		"zQvzZlRvddvpNLpZrMNNLZ",
		"HLvWFHHlFQvzHnnlnvQqhzWvstBwbGVtstjGqjjwqGGCcwGq",
		"JNpNdzzdJhNnfNGBZLqZqlhvSZSG",
		"QswtcmmwwmTmwwcwZSLlZLDSvSvlBZQD",
		"FsVFBbFgFsPwtVBTwgTPcsmpzdNngfzfpCzJdzCJzNCndn",
		"qcvrLBppgpWWWgLcpzPfhNDqdzqwDDzwhV",
		"MZFjFnHFMHbMntMtnwStfddPhDffDfzDfS",
		"QmnjMZnlHjmnMGFnFlMmjlZWzLgsGgcrspBBLCBcgvgBRC",
		"sdfWHjZfrZrSPMCQ",
		"zqtWRDDDRMbrQJPQ",
		"zwhwzmqwzmFpWzvFqBmFvjNHlHfgVLBgdfVfNVjLsl",
		"lRlBTlvlZfhtbGBWtFBz",
		"cqCNjjqjrNrcNjwDqNPCVrSQStSWshFhtQhbQzGzmFCG",
		"HjPPzMcdNqjcNHMqPjdpgpZflfdgnTfdlvlJ",
		"VpwQJVRtHplnnwtppHhqWBCfVdNNPqPBPWsBDq",
		"jzLZCrvvrZjZvqNffvDNDcWDWd",
		"LTrZZLFZbgTzgjZZjFClJhTHTplQpmnQlpmpQR",
		"JGJnSWLGSpWHVHwGGJHpZdwPdTTPMdTMDdlzccPMPv",
		"gqrrmtbrbgggqgBtqmRSrFgNCzvMDvlMPDdddvzBcPMMMDBd",
		"gjrmRgmtRggFtqjbhgbjrtnJJHWLHQWZZLhZsLLGHhSL",
		"BtTDNggLRPdWQHqggg",
		"wrVpVVlCJVGMMJVdHWSdPSqqRwSQSP",
		"vCVrpvvGjlphBRmZBhmBhBND",
		"lqDcZGcSSqSqbDnccSLJgHgLRfnvvJRLmvWJ",
		"FVCFPChQzVhmsFBgddRgJBfdNfJdfv",
		"FzCpmTQzjQCThppTSttqDccMTDGcDG",
		"QCSGBGCrCsMBTCQwMGSfvvLNNnnVLDlNVNDdVdlr",
		"ZHtPffjWbqgtmnNdvljFnFhdVv",
		"JRWbmgmRJtmJMGGwSBBRRRfQ",
		"LqNrCfCQQhtgnPnc",
		"JWBrWrVlbWgbbtcb",
		"VwvTBprdrVJVNLNMNNqfqpjN",
		"bjVqdHrdqVHPsPNbqHbqNdjFGRwRGlttRtMtRtFFGMLHJw",
		"cfSpZnBZWQBZJlGRJJcwGMGL",
		"WWBhTMgDTZghVjgjssbrbddd"
	};

	//Initialise the counter map.
	std::vector<char> missplacedItems;

	//Loop through the input and find which letters appear in both comparments
	//of every rucksack.
	for (int i = 0; i < input.size(); i++) {
		const std::string& currentString = input[i];
		//split the string into both halves.
		std::string firstHalf;
		std::string secondHalf;
		for (int j = 0; j < currentString.size(); j++) {
			if (j < currentString.size() / 2) {
				firstHalf = firstHalf + currentString[j];
			}
			else {
				secondHalf = secondHalf + currentString[j];
			}
		}



		//Get the characters that appear in both halves.
		bool inBothHalves = false;
		int missplacedItemIndex = 0;
		for (int j = 0; j < firstHalf.size() && !inBothHalves; j++) {
			for (int k = 0; k < secondHalf.size(); k++) {
				if (firstHalf[j] == secondHalf[k]) {
					//If the character is in both halves add it to the list of missplaced items.
					missplacedItemIndex = j;
					inBothHalves = true;
				}
			}
		}
		missplacedItems.push_back(firstHalf[missplacedItemIndex]);

	}

	//Sum the final value print it.
	int prioritySum = 0;
	for (int i = 0; i < missplacedItems.size(); i++) {
		prioritySum += ConvertCharToPriority(missplacedItems[i]);
	}
	std::cout << "Priority Sum Value: " << prioritySum << std::endl;

	//PART 2 CODE.
	int badgeSums = 0;
	for (int i = 0; i < input.size(); i += 3) {
		std::string elf1 = input[i];
		std::string elf2 = input[i + 1];
		std::string elf3 = input[i + 2];
		badgeSums += ConvertCharToPriority(FindCommonCharacter(elf1, elf2, elf3));
	}

	//Print the badge sums.
	std::cout << "Badge Sum Value: " << badgeSums << "\n-------------------" << std::endl;
}

int Day3::ConvertCharToPriority(const char& a_char) {
	static const std::array<char, 52> characterValues = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
		'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
		's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A',
		'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
		'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};
	for (int i = 0; i < characterValues.size(); i++) {
		if (characterValues[i] == a_char) {
			return i + 1;
		}
	}

	//Return -100 if the character was not found.
	return -100;
}

char Day3::FindCommonCharacter(const std::string& a_string1, const std::string& a_string2, const std::string& a_string3) {
	for (int i = 0; i < a_string1.size(); i++) {
		for (int j = 0; j < a_string2.size(); j++) {
			for (int k = 0; k < a_string3.size(); k++) {
				if (a_string1[i] == a_string2[j] && a_string2[j] == a_string3[k]) {
					char common = a_string1[i];
					return common;
				}
			}
		}
	}
}